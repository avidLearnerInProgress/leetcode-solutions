class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int len = n+2;
        vector<int> arr = {1};
        for(auto& num : nums)
            arr.push_back(num);
        
        arr.push_back(1);
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int gap = 2; gap < len; gap++) {
            for(int left = 0; left < len-gap; left++) {
                int right = left+gap;
                int cur = 0;
                for(int mid = left+1; mid < right; mid++) {
                    cur = max(cur, dp[left][mid]+dp[mid][right]+arr[left]*arr[mid]*arr[right]);
                }
                dp[left][right] = cur;
            }
        }
        return dp[0][len-1];
    }
};
