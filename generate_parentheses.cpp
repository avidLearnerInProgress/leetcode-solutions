class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>();
        int open = n, close = n;
        vector<string> result;
        solve("", open, close, result);    
        return result; 
    }
    
    void solve(string operations, int open, int close, vector<string> &result) {
        
        if(open == 0 and close == 0){
            result.push_back(operations);
            return;
        }
        
        if(open > 0) {
            solve(operations + "(", open-1, close, result);
        }
        if(close > open ) {
            solve(operations + ")", open, close-1, result);
        }
        return;
    }      
};
