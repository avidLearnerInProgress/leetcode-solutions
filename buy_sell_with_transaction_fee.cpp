class Solution {
public:
    int dp[50001][2];
    int solve(vector<int> &prices, int fee, int own, int index) {
        
        //basecase
        if(index == prices.size()) 
            return 0;
        
        if(dp[index][own] != -1) 
            return dp[index][own];
        
        if(own) {
            int case1 = prices[index] + solve(prices, fee, 0, index + 1);
            int case2 = solve(prices, fee, 1, index + 1);
            return dp[index][own] = max(case1, case2);
        }
        
        else {   
            int case1 = -(fee + prices[index]) + solve(prices, fee, 1, index + 1);
            int case2 = solve(prices, fee, 0, index + 1);
            return dp[index][own] = max(case1, case2);
        }   
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        /*
        n = len(prices)
        if you own a stock at day `i`, you have two choices -
            - sell the stock at day `i + 1` and find the max profit incurred after day `i + 1` to `n`
            - do not sell the stock at day `i + 1` and find max profit incurred after day `i + 1` to `n`
            
        if you do not own a stock at day `i` you have two choices -
            - own a stock at day `i + 1` and find the max profit incurred after day `i + 1` to `n`
            - do not sell the stock at day `i + 1` and find max profit incurred after day `i + 1` to `n`
        */
        memset(dp, -1, sizeof dp);
        return solve(prices, fee, 0, 0);
    }
};
