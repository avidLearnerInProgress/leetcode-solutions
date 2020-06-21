class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {  
        
        if (!matrix.size())
            return;
        int m = matrix.size(), n = matrix[0].size();
        bool isColumn = false, isRow = false;
        
		// check if the index does have a zero or not
        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0) {
                isColumn = true;
                break;
            }
        }
       for (int j=0; j<n; j++) {
            if (matrix[0][j] == 0) {
                isRow = true;
                break;
            }
        }
        // scan and place all the zeros in column and row 
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        //Fill all the booleans with respected values
        for (int i=1; i<m; i++) {
            if (matrix[i][0] == 0) {
                for (int j=1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j<n; j++) {
            if (matrix[0][j] == 0) {
                for (int i=1; i<m; i++) {
                    matrix[i][j]=0;
                }
            }
        }
        if (isRow) {
            for (int j=0; j<n; j++) matrix[0][j] = 0;
        }
        if (isColumn)
            for (int i=0; i<m; i++) matrix[i][0] = 0;

    }
};