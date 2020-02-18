class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size()));
        
        for(auto i=0; i<grid.size(); i++){
            for(auto j=0; j<grid[0].size(); j++){
                
                dp[i][j] += grid[i][j];
                
                if(i > 0 && j >0)
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                
                else if(i > 0)
                    dp[i][j] += dp[i-1][j];
                
                else if(j > 0)
                    dp[i][j] += dp[i][j-1];
    
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
/*
 int minPathSum(vector<vector<int>>& grid) {
        // DP problem
        // DP[i,j] -> minimum sum of reaching i,j
        int rows = grid.size();
        int cols = grid[0].size();
        
        // DP grid (rows X cols) initialized to grid[0][0] element
        vector<vector<int>> DP(rows,vector<int>(cols,grid[0][0]));
        
        // Fill first column (0) 
        // DP[i,0] = prefix sum along first column = DP[i-1,0] + grid[i][0]
        for (int i=1;i<rows;++i) {
            DP[i][0] = DP[i-1][0] + grid[i][0];
        }
        
        // Fill first row (0)
        // DP[0,i] = prefix sum along first row = DP[0,i-1] + grid[0][i]
        for (int i=1;i<cols;++i) {
            DP[0][i] = DP[0][i-1] + grid[0][i];
        }
        
        // Fill the rest of the matrix
        // We can only go right and down 
        // i,j can be reached from the above it (i-1,j) OR from its left (i,j-1) 
        // We minimize the cost for both
        for (int i=1;i<rows;++i) {
            for (int j=1;j<cols;++j) {
                DP[i][j] = min(DP[i-1][j],DP[i][j-1]) + grid[i][j];
            }
        }
        
        // return 
        return DP[rows-1][cols-1];
    }

    */