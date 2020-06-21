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