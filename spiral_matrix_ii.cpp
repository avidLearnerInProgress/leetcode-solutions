class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> spiral(n, vector<int>(n,0));
        int row_begin = 0, row_end = n-1, col_begin = 0, col_end = n-1;
        int c = 1;
        while(row_begin <= row_end and col_begin <= col_end) {
            
            for(auto i=col_begin; i<=col_end; i++)
                spiral[row_begin][i] = c++;
            row_begin++;
            
            for(auto i=row_begin; i<=row_end; i++)
                spiral[i][col_end] = c++;
            col_end--;
            
            if(row_begin <= row_end) {
                for(auto i=col_end; i>=col_begin; i--)
                    spiral[row_end][i] = c++;
                row_end--;
            }
            
            if(col_begin <= col_end) {
                for(auto i=row_end; i>=row_begin; i--)
                    spiral[i][col_begin] = c++;
                col_begin++;
            }
        }
        return spiral;
    }
};
