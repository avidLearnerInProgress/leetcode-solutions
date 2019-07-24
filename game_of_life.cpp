class Solution {
    public:
        int countLiveNeighbors(const vector<vector<int>>& board, int i, int j, int m, int n) {
            int count = 0;        
            //edgecases for rows
            if(i > 0){ //consider [i-1][j-1], [i-1][j], [i-1][j+1]
                if(j > 0 && board[i - 1][j - 1]) ++count; //prev col prev row 
                if(board[i - 1][j]) ++count; //prev row same col
                if(j + 1 < n && board[i - 1][j + 1]) ++count; //prev row next col
            }

            if(i + 1 < m){ //consider [i+1][j-1], [i+1][j], [i+1][j+1]
                if(j > 0 && board[i + 1][j - 1]) ++count; //next row prev col
                if(board[i + 1][j]) ++count; //next row same col
                if(j + 1 < n && board[i + 1][j + 1]) ++count; //next row next col
            }

            //edge cases for cols
            if(j > 0 && board[i][j - 1]) ++count; // same row prev col
            if(j + 1 < n && board[i][j + 1]) ++count; //same row next col

            return count;
        }
    
        void gameOfLife(vector<vector<int>>& board) {
            int num_rows = board.size();
            int num_cols = board[0].size();
            vector<vector<int>> res(num_rows, vector<int>(num_cols, 0));
            for (int i = 0; i < num_rows; ++i) {
                for (int j = 0; j < num_cols; ++j) {
                    int count = countLiveNeighbors(board, i, j, num_rows, num_cols);
                    if (board[i][j] == 0) {
                        if (count == 3)
                            res[i][j] = 1;
                    } else {
                        if (count == 2 || count == 3)
                            res[i][j] = 1;
                    }
                }
            }
            board = res;
            return ;
        }
};