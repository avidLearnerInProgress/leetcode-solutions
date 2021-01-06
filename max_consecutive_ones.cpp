class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, mxc = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                mxc = max(cnt, mxc);
            }
            else{   
                cnt = 0;
            }
        
        }
        if(mxc == INT_MIN)
            return nums[0];
        else
            return mxc;
    }
};
