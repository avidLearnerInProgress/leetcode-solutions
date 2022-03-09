// //fsm based solution

// class Solution {
// private:
//     const int STATE_NUM = 3, STEP_NUM = 2, S_BUY = 0, S_SELL = 1, S_COOL = 2;
// public:
//     int maxProfit(vector<int>& prices) {
//         int state[STATE_NUM][STEP_NUM], i, j, steps = prices.size(),cur = 0, next = 1;
        
//         fill_n(&state[0][0], STATE_NUM*STEP_NUM, INT_MIN);
        
//         for(i=0,state[0][0]=0;i<steps;++i, swap(cur, next)) {
//             state[S_BUY][next]  = max(state[S_BUY][cur], state[S_COOL][cur]);
//             state[S_SELL][next] = max(state[S_BUY][cur]-prices[i], state[S_SELL][cur]);
//             state[S_COOL][next] = state[S_SELL][cur] + prices[i];
//         }
//         return max(state[S_BUY][cur], state[S_COOL][cur]);
//     }
// };


class Solution {
public:
    
    int dp[50001][2][2];
    int solve(vector<int> &prices, int cool, int own, int index) {
        
        //basecase
        if(index == prices.size()) 
            return 0;
        
        if(dp[index][own][cool] != -1) 
            return dp[index][own][cool];
        
        if(own) {
            int case1 = prices[index] + solve(prices, 1, 0, index + 1);
            int case2 = solve(prices, 0, 1, index + 1);
            return dp[index][own][cool] = max(case1, case2);
        }
        
        else {   
            int case1 = (cool == 1) ? 0 : (-prices[index] + solve(prices, 0, 1, index + 1));
            int case2 = solve(prices, 0, 0, index + 1);
            return dp[index][own][cool] = max(case1, case2);
        }   
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, 0, 0);
        
    }
};
