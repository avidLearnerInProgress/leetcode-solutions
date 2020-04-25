class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int perimeter, area=0, repeated=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    area++;
                    
                    if(i > 0 and grid[i-1][j] == 1) repeated++;
                    if(j > 0 and grid[i][j-1] == 1)
                        repeated++;
                }
            }
        }
        return (4 * area) - (2 * repeated);
    }
};