class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int steps = 0,r = grid.size(),c = grid[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) {
                    q.push({i-1, j});
                    q.push({i+1, j});
                    q.push({i, j-1});
                    q.push({i, j+1});
                }
            }
        }
        while(!q.empty()) {
            int size = q.size();
            steps++;
            for(int k = 0; k < size; k++) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i >= 0 && j >= 0 && i < r && j < c&& grid[i][j] == 0) {
                    grid[i][j] = steps;
                    q.push({i-1, j});
                    q.push({i+1, j});
                    q.push({i, j-1});
                    q.push({i, j+1});
                }
            }
        }
        return steps == 1 ? -1 : steps - 1;
    }
};
