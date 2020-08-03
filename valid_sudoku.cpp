class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> used(9, false);

        for (int i = 0; i < 9; ++i) {
            fill(used.begin(), used.end(), false);
            
            // check row
            for (int r = 0; r < 9; ++r) {
                if (!check(board[r][i], used))
                    return false;
            }
            
            fill(used.begin(), used.end(), false);
            
            // check col
            for (int c = 0; c < 9; ++c) {
                if (!check(board[i][c], used))
                    return false;
            }
        }
        
        
        //for board
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) { 
                
                //for each square of 9*9 set the vector to false
                
                fill(used.begin(), used.end(), false);
                
                for(int r=3*i; r<3*i+3; r++) {
                    for(int c=3*j; c<3*j+3; c++) {
                        if(!check(board[r][c], used)) return false;
                    }
                }
            }
        }
        
        
        //when all cases evaluate to true...
        return true;
    }
    
    bool check(char ch, vector<bool>& used) {
        if (ch == '.') return true;
        if (used[ch - '1']) return false;
        used[ch - '1'] = true;
        return true;
    }

};
