
//more readable, less optimal
class Solution {
private:
    
    bool isValidRow(vector<vector<char>>& board, int& row) {
        
        set<int> digits; // SC: O(1)
        for(int c = 0; c < 9; c++) {
            if(digits.find(board[row][c]) != digits.end()) { // O(log(row_size))
                return false;
            }
            if(board[row][c] != '.') {
                digits.emplace(board[row][c]);
            }
        }
        digits.clear();
        return true;
    }
    
    bool isValidColumn(vector<vector<char>>& board, int& col) {
        
        set<int> digits; // SC: O(1)
        for(int r = 0; r < 9; r++) {
            if(digits.find(board[r][col]) != digits.end()) { // O(log(row_size))
                return false;
            }
            if(board[r][col] != '.') {
                digits.emplace(board[r][col]);
            }
        }
        digits.clear();
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //validate all rows
        for(int r = 0; r < 9; r++) {
            if(!isValidRow(board, r)) { //O(r)
                return false;
            }
        }
        
        //validate all cols
        for(int c = 0; c < 9; c++) {
            if(!isValidColumn(board, c)) { //O(r)
                return false;
            }
        }
        
       //valid 3x3 blocks
        set<int> digits;        
        for(int blockRow = 0; blockRow < 3; blockRow++) {
            for(int blockCol = 0; blockCol < 3; blockCol++) {
                
                for(int r = 3 * blockRow; r < 3 * blockRow + 3; r++) {
                    for(int c = 3 * blockCol; c < 3 * blockCol + 3; c++) {
                        
                        if(digits.find(board[r][c]) != digits.end()) {
                            return false;
                        }
                        if(board[r][c] != '.') {
                            digits.emplace(board[r][c]);
                        }
                    }
                }
                digits.clear();
            }
        }
        
        return true;
    }
};



//less readable, more optimal
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
