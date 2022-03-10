class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int firstSell = 0, secondSell = 0;
        int firstBuy = INT_MIN, secondBuy = INT_MIN;
        
        for(int price : prices){
            firstBuy = max(firstBuy, -price); //since you buy stock we invest our money.. hence we write -price
            firstSell = max(firstSell, firstBuy + price); //sell stock..so we get money hence, firstBuy + price
            //made some day 1 profit...
            //now for day 2 we start from existing profit .. ie. from firstSell
            secondBuy = max(secondBuy, firstSell - price); //same logic for second 
            secondSell = max(secondSell, secondBuy + price);   
        }
        return secondSell;
        
        
    }
};

//dp based solution generalizing to k transactions
class Solution {
public:

    int dp[500001][2][3];
    int solve(vector<int> &prices, int own, int index, int transaction_count) {
        
        //basecase
        if(index >= prices.size() or transaction_count == 0)  
            return 0;
        
        if(dp[index][own][transaction_count] != -1) 
            return dp[index][own][transaction_count];
        
        if(own) {
            int case1 = prices[index] + solve(prices, 0, index + 1, transaction_count - 1);
            int case2 = solve(prices, 1, index + 1, transaction_count);
            return dp[index][own][transaction_count] = max(case1, case2);
        }
        
        else {   
            int case1 = -prices[index] + solve(prices, 1, index + 1, transaction_count);
            int case2 = solve(prices, 0, index + 1, transaction_count);
            return dp[index][own][transaction_count] = max(case1, case2);
        }   
    }
    
    int maxProfit(vector<int>& prices) {
       
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, 0, 2);
        
    }
};
