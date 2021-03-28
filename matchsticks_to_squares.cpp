class Solution {
    int n=0,target; 
	//it will store the result of previously used states
    int vis[1<<16];
    bool dfs(int num,int combo,int step,vector<int>&nums)
    {
        if(num==0)
        {
            if(step==4)return 1; //final part has been filled completely
            step++;  //if step<4, we should move to fill next part
            num=target;  //new part should also have the same target.
        }
        if(num<0)return 0;
        if(vis[combo]!=-1)return vis[combo];  //if this combination has been tried before return the result directly.
        for(int i=0;i<n;i++)
        {
            int mask=1<<i;
            if(mask&combo)continue;  //don't use an element more then once, bits of combo represents which element has been used.
            if(dfs(num-nums[i],combo|mask,step,nums))return vis[combo]=1;  //if all 4 parts have sum==target, we have built the square
        }
        return vis[combo]=0; //after trying every combo if nothing works return 0.
    }
public:
    bool makesquare(vector<int>& nums) {
        n=nums.size();
        if(n<4)return 0;            //array should have at least 4 elements.
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)return 0;      //sum of array should be divisible by 4.
        target=sum/4;            //each of the 4 parts of array should have this sum.
        for(auto it:nums)if(it>target)return 0;   //an element greater than taget can't be used, but we must use all the elements
		//marking every state not visited.
        memset(vis,-1,sizeof(vis));
        return dfs(target,0,1,nums);
    }
};
	
