class Solution {
    int dp[71][71][71];
    int delta[3] = {0, -1, 1};
    
    bool isNotInRange(int &c1, int &c2, int &m, int &n) {
        return c1 < 0 || c2 < 0 || c1 >= n || c2 >= n; 
    }
        
    int cherryPickupHelper(vector<vector<int>>& grid, int r, int c1, int c2) {
        int m = grid.size(), n = grid[0].size();
        
        if(r == m) {
            return 0;
        }
        
        if(isNotInRange(c1, c2, m, n)) {
            return INT_MIN;
        }
        
        if(dp[r][c1][c2] != -1) { //memoized call
            return dp[r][c1][c2];
        }
        
        int currMaxCherryCount = 0;
        
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                currMaxCherryCount = max(currMaxCherryCount, cherryPickupHelper(grid, r + 1, c1 + delta[i], c2 + delta[j]));
            }
        }
        
        currMaxCherryCount += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        
        return dp[r][c1][c2] = currMaxCherryCount;     //store computation
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
         
        //too much of work in this problem!! DP
        //both robots move simultaneously (this reduces a dimension in terms of storage for the dp matrix)
        //three directions .. max_cherries: 3 * r1 + 3 * r2 => 9 different states 
        //one edgecase - r1 and r2 at same position, add value of grid only once
        //Top Down approach
        
        int m = grid.size();
        if(!m) return 0;
        
        int n = grid[0].size();
    
        memset(dp, -1, sizeof dp); 
        return cherryPickupHelper(grid, 0, 0, n - 1);
    }
};

