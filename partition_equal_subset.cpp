class Solution {
public:
    
    /*
    best solution
    bool cal(vector<int> nums, int sum, int i) {
        if (i == nums.size() || sum < nums[i]) return false;
        if (sum == nums[i]) return true;
        
        return cal(nums, sum - nums[i], i+1) || cal(nums, sum, i+1);
    }
    
    bool canPartition(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum%2) return false;
         sum /= 2;
        return cal(nums, sum, 0);
    }
    */
    
    bool subsetSumDP(vector<int>& nums, int sum, int n) {

        //dp matrix 
        //first col => true, first row => false
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum+1));
        
        //sum > 0 but n is 0 is not possible.. first row of dp matrix
        for(int i=0; i<=sum; i++) dp[0][i] = false;
        
        //empty sum is subset => {}
        for(int i=0; i<=n; i++) dp[i][0] = true;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                
                if(nums[i-1] <= j) //current value is less than sum => include or exclude
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j]; //current value > sum; definitely exclude
            }
        }
        return dp[n][sum]; 
    }
    
    bool canPartition(vector<int>& nums) {
        auto sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        cout<<sum<<"\n";
        if(sum % 2  != 0) return false;
        return subsetSumDP(nums, sum/2, nums.size());
        
    }
};
