class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int maxProfit = 0;
        int i = 0, N = prices.size() - 1;
        int buy = 0, sell = 0;
        
        while(i < N){
            //current_price > next_price
            while(i < N && prices[i+1] <= prices[i]) i++; //break when current_price !< next_price
            buy = prices[i];
            while(i < N && prices[i+1] > prices[i]) i++;
            sell = prices[i];
            maxProfit += sell - buy;
        }
        return maxProfit;
    }
};