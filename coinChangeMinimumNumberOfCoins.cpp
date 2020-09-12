class Solution {
public:
    int change(int amount, vector<int>& coins) {
       
        int denominations = coins.size();
        int dp[denominations + 1][amount + 1];


        //set first column as 1 as there is 1 way to get sum of 0 irrespective of any denomination of coin that we have 
        for(int i=0; i<=denominations; i++) dp[i][0] = 1;

        //set first row as 0 as irrespective of the sum, for 0 domination we will get 0 ways to reach upto sum
        for(int j=1; j<=amount; j++) dp[0][j] = 0;


        for(int i=1; i<=denominations; i++) {
            for(int j=1; j<=amount; j++) {

                //include exclude principle => similar to unbounded knapsack
                if(coins[i-1] <= j) {
                    //exclude + include
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];  //in include its i in row and not i-1 because of unbounded knapsack
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[denominations][amount]; //total number of ways, coins of x denomination can get upto target sum
    }
};
