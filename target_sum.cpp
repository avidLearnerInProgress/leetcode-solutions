class Solution {
public:
    
    int countSubsetsWithSumDP(vector<int> v, int sum) {
        int n = v.size();
        int dp[n + 1][sum + 1];

        for(int i=0; i<=sum; i++) {
            dp[0][i] = false;
        }

        for(int j=0; j<=n; j++) {
            dp[j][0] = true;
        }


        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {

                if(v[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    //include + exclude
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - v[i-1]];
                }
            }
        }
        return dp[n][sum];
    }


    int countSubsetWithDifferenceK(vector<int> v, int difference) {
        
        long long arr_sum = 0, sum = 0;
        for(auto n : v) arr_sum += n;
        long long int _t = arr_sum + difference;
            
        if((_t) % 2 != 0) return 0;
        if(difference > arr_sum) return 0;
        else
            sum = (difference + arr_sum) / 2;
        return countSubsetsWithSumDP(v, sum);
    }

    
    int findTargetSumWays(vector<int>& nums, int S) {
        return countSubsetWithDifferenceK(nums, S);
    }
};
