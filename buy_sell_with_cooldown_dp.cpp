//fsm based solution

class Solution {
private:
    const int STATE_NUM = 3, STEP_NUM = 2, S_BUY = 0, S_SELL = 1, S_COOL = 2;
public:
    int maxProfit(vector<int>& prices) {
        int state[STATE_NUM][STEP_NUM], i, j, steps = prices.size(),cur = 0, next = 1;
        
        fill_n(&state[0][0], STATE_NUM*STEP_NUM, INT_MIN);
        
        for(i=0,state[0][0]=0;i<steps;++i, swap(cur, next)) {
            state[S_BUY][next]  = max(state[S_BUY][cur], state[S_COOL][cur]);
            state[S_SELL][next] = max(state[S_BUY][cur]-prices[i], state[S_SELL][cur]);
            state[S_COOL][next] = state[S_SELL][cur] + prices[i];
        }
        return max(state[S_BUY][cur], state[S_COOL][cur]);
    }
};
