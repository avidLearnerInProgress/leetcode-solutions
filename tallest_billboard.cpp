class Solution {
public:
     int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(),rods.end(),0);
        vector<int> dp(sum*2+1,-1);
        dp[sum] = 0;
        for(int& r:rods) {
            vector<int> prev = dp;
            for(int i=0;i<=2*sum;i++) {
                if(prev[i]==-1)continue;
                dp[i+r]=max(dp[i+r],prev[i]+r);
                dp[i-r]=max(dp[i-r],prev[i]);
            }
        }
        return dp[sum];
    }
};
