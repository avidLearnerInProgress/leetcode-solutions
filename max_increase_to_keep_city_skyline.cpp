class Solution {
public:
    //TC: O(n*2) SC: O(n) => don't think its possible in anything less than n * 2
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> maxIncreaseInRow(n, 0);
        vector<int> maxIncreaseInCol(n, 0); // n * n
        int maxSumIncrease = 0;
        
        
        //for any skyline problem we consider the max at any index...
        //so for any index(i, j) in grid => we can grow the current building to the height of min from maxInCol or maxInRow.
        
        //get max for every row and every column
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                maxIncreaseInRow[i] = max(maxIncreaseInRow[i], grid[i][j]);
                maxIncreaseInCol[j] = max(maxIncreaseInCol[j], grid[i][j]);
            }
        }
        
        //simple math - 
            // take min of both maxRow and maxCol at i and j indexes.
            // min because we don't want to change the skyline. 
            // example: maxIncreaseInRow[i] > grid[i][j] => this operation will change the skyline.
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                maxSumIncrease += min(maxIncreaseInRow[i], maxIncreaseInCol[j]) - grid[i][j];
            }
        }
        
        return maxSumIncrease;
        
    }
};
