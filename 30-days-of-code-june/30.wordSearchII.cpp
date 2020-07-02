class Solution {
private:
    //timepass naive founder in the grid..
    bool found(vector<vector<char>> &board, string &word, int i, int j, int count){
        //base case..
        if(count == word.length()) return true;
        
        //get out of here..
        if(i <0 || j < 0 || j >= board.size() || i >= board.size() || word[count] != board[i][j])
            return false;
        
        count++;
        char temp = board[i][j];
        board[i][j] = '*';
        bool present = found(board, word, i + 1, j , count) || found(board, word, i - 1, j, count) || found(board, word, i, j + 1, count) || found(board, word, i, j-1, count);
        
        board[i][j] = temp;
        return present;
    }
    
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            
        if(board.size() == 0 || words.size() == 0) return {};
        int m = board.size(), n = board[0].size();
        vector<string> result;
        
        for(auto word: words){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j] == word[0] && found(board, word, i, j, 0)){
                        result.push_back(word);
                    } 
                }
            }
        }
        return result;
    }
};
