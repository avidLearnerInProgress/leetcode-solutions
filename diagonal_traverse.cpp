class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int row = 0, col = 0, k = 0;
        int m = matrix.size(), n = matrix[0].size();       
        
        vector<int> result;
        for(int i=0; i<(m*n); i++){
            
            result.push_back(matrix[row][col]);
            
            
            if((row+col) % 2 == 0){ //even diagonal
            
                if(col == n-1) row++;
                else if(row == 0) col++;
                else{
                    row--;
                    col++;
                }
            }
            
            else{ //odd diagonal 
                if(row == m-1)
                    col++;
                else if(col == 0)
                    row++;
                else{
                    col--;
                    row++;
                }
            }
        }
        return result;
    }
};