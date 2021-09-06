class Solution {
    vector<int> dp;
    int minCost(vector<int> &days, vector<int> &costs, int currentIdx) {
        
        int n = days.size();
        if(currentIdx >= n) return 0;
        
        if(dp[currentIdx]) return dp[currentIdx];
        
        int costDay = costs[0] + minCost(days, costs, currentIdx + 1);
        
        int i;
    
        for(i = currentIdx; i < n and days[i] < days[currentIdx] + 7; i++) {
        }
        int costWeek = costs[1] + minCost(days, costs, i);
        
        for(i = currentIdx; i < n and days[i] < days[currentIdx] + 30; i++) {
        }
        int costMonth = costs[2] + minCost(days, costs, i);
        
        dp[currentIdx] = min({costDay, costWeek, costMonth});
        return dp[currentIdx];
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(367); //constraints --
        return minCost(days, costs, 0);
        
    }
};
