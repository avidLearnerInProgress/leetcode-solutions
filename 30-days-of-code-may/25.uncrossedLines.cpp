class Solution {
   public:
   int maxUncrossedLines(vector<int>& A, vector<int>& B) {
       int n=A.size();
        int m=B.size();
        
        int dp[n+1][m+1];
        
        
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(A[i-1]==B[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};