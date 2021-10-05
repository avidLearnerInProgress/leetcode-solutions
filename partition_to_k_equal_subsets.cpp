class Solution {
public:
    int n;
    int visited[17];
    
    bool possible(vector<int>& nums, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        
        if(currSum == subsetSum) {
            return possible(nums, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum+nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += nums[i];
            
            if(possible(nums, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(visited, 0, sizeof(visited));
        n = nums.size();
        
        if(sum%k != 0)
            return false;
        
        int subsetSum      = sum/k;
        int numsIndex      = n-1;
        int currSum        = nums[numsIndex];
        visited[numsIndex] = 1;
        
        return possible(nums, numsIndex, currSum, subsetSum, k);
        
    }
};
