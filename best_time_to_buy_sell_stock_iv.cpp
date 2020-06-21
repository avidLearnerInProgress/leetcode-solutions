class Solution {
public:
    int greedy(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += (prices[i] > prices[i - 1]) ? (prices[i] - prices[i - 1]) : 0;
        }
        return profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n < 2 || k < 1) return 0;
        
        if(k > n/2){
            return greedy(prices);       
        }
        
        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        
        for(auto p : prices){    
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p);
            
            for(int j=1; j<k; j++){
                buy[j] = max(buy[j], (sell[j-1] - p));
                sell[j] = max(sell[j], (buy[j] + p));
            }
        }
        return sell.back();
    }
};