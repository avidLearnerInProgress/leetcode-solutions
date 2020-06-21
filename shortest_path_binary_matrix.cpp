class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size(), path_steps = 0;
        vector<vector<bool>> visited(r, vector(c, false));
        queue<pair<int, int>> q;
        
        if(grid[0][0] == 1 || grid[r-1][c-1]== 1) //indicating blocked state
            return -1;
        
        int deviations[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        
        q.push({0,0});
        visited[0][0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            path_steps++;
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == r - 1 && y == c - 1) //reached end state
                        return path_steps;
                
                for(int j=0; j<8; j++){
                    int newx = x + deviations[j][0];
                    int newy = y + deviations[j][1];
                    
                    if(newx >=0 && newx < r && newy >=0 && newy < c && !visited[newx][newy] && grid[newx][newy] == 0){
                        q.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
                
            }
        }
        return -1;
    }
};


/*
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        r, c = len(grid), len(grid[0])
        if grid[0][0] == 1 or grid[r-1][c-1] == 1: #blocked state
            return -1
        queue = collections.deque([(0,0,1)])
        while queue:
            x, y, count = queue.popleft()
            if x == r - 1 and y == c - 1: #end state
                return count      
            for ddx, ddy in ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)):
                dx, dy = x + ddx, y + ddy
                if dx >= 0 and dx < r and dy >= 0 and dy < c and not grid[dx][dy]:
                    queue.append((dx, dy, count + 1))
                    grid[dx][dy] = 1
        return -1
*/