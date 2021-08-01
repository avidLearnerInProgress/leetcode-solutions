class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        int maxx = 0, islandId = 2;
        int m = grid.size(), n = grid[0].size();
        map<int, int> mp;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int sz = getIslandSize(i, j, m, n, islandId, grid);
                    maxx = max(maxx, sz);
                    mp.insert({islandId++, sz});
                }
            }
        }
        vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    for(auto &[dx, dy] : directions) {
                        int x = dx + i, y = dy + j;
                        if(x > -1 and y > -1 and x < m and y < n and grid[x][y] != 0) s.insert(grid[x][y]);
                    }
                    
                    int sum = 1;
                    for(auto id : s) {
                        sum += mp[id];
                    }
                    maxx = max(maxx, sum);
                }
            }
        }
        return maxx;
    }
    
    
    int getIslandSize(int i, int j, int m, int n, int islandId, vector<vector<int>> &grid) {
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != 1) return 0;
        grid[i][j] = islandId;
        
        int left = getIslandSize(i, j - 1, m, n, islandId, grid);
        int right = getIslandSize(i, j + 1, m, n, islandId, grid);
        int top = getIslandSize(i - 1, j, m, n, islandId, grid);
        int bottom = getIslandSize(i + 1, j, m, n, islandId, grid);
        
        return left + right + top + bottom + 1;
    }
};
