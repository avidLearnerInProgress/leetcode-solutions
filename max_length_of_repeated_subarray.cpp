class Solution {
public:
    int longestCommonSubstringDP(vector<int> &x, int m, vector<int> &y, int n) {
    
        int dp[m+1][n+1]; //store the lengths and play around with the lengths
        int result = INT_MIN;

        for(int i=0; i<=m; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;


        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(x[i-1] == y[j-1]) { //found a match
                        dp[i][j] = dp[i-1][j-1] + 1; //check for the cell diagaonally above to hold the lcs at last matched character
                        result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }

        // for(int i=0; i<=m; i++) {
        //     for(int j=0; j<=n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return result == INT_MIN ? 0 : result;
    }
    

        
    int findLength(vector<int>& A, vector<int>& B) {
        return longestCommonSubstringDP(A, A.size(), B, B.size());
    }
};
