class Solution {
public:
    const vector<int> direction = {0, 1, 0, -1, 0}; //improvement instead of performing 4 calls
    int dfs(vector<vector<char>>& grid, int i, int j) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return 0;
        
        grid[i][j] = '0';
        for(int k=0; k<4; k++)
            dfs(grid, i +
                direction[k], j + direction[k + 1]);
        return 1;    
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int islands = 0;
        for(int i=0;  i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                islands += dfs(grid, i, j);        
            }
        }
        return islands;
    }
};

# class Solution:
#     def dfs(self, grid, i , j):
#         if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] != '1':
#             return
#         grid[i][j] = "$"
#         self.dfs(grid, i + 1, j)
#         self.dfs(grid, i - 1, j)
#         self.dfs(grid, i, j + 1)
#         self.dfs(grid, i, j - 1)
        
#     def numIslands(self, grid: List[List[str]]) -> int:
#         if not grid:
#             return 0
#         islands = 0       
#         for i in range(len(grid)):
#             for j in range(len(grid[0])):
#                 if grid[i][j] == '1':
#                     self.dfs(grid, i, j)
#                     islands += 1
        
#         return islands
