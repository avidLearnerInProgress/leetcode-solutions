// class Solution:
//     def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
//         m, n = len(grid), len(grid[0])
        
//         def dfs(i, j):
//             if 0 <= i < m and 0 <= j < n and grid[i][j]:
//                 grid[i][j] = 0
//                 return 1 + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i + 1, j) + dfs(i, j - 1)
//             return 0

//         areas = [dfs(i, j) for i in range(m) for j in range(n) if grid[i][j]]
//         return max(areas) if areas else 0
    
class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if(i >= 0 and i < grid.size() and j >= 0 and j < grid[i].size() and grid[i][j]) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i - 1, j) + dfs(grid, i, j - 1) + dfs(grid, i + 1, j) + dfs(grid, i, j + 1);
        }
        else return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j]) 
                    maxArea = max(maxArea, dfs(grid, i , j));
                
            }
        }
        
        return maxArea;
    }
};
