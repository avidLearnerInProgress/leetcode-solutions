class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         
        int m = obstacleGrid.size(), n = obstacleGrid[0].size(), i , j;
        
        vector<vector<long>> dp (m, vector<long> (n, 0)); 
        
        for (i = 0; i < n;) {
            if(obstacleGrid[0][i] == 0) 
                dp[0][i++] = 1;
            else
                break;
        }
            
        for (j = 0; j < m;){
            if(obstacleGrid[j][0] == 0) 
                dp[j++][0] = 1;
            else
                break;
        }
        
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
