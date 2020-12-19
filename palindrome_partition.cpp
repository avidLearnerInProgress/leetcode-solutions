class Solution {

private:
    
bool isPalindrome(string s, int low, int high) {
    
    while(low < high) {
        if(s[low++] != s[high--]) return false;
    }
    return true;
} 
    
void backtrack(vector<vector<string>> &global_result, vector<string> &local_result, string &s, int start) {
   if(start == s.size()) {
        global_result.push_back(local_result);
       return;
    }

    for(int i=start; i<s.size(); i++) {
        if(isPalindrome(s, start, i)) {
            local_result.push_back(s.substr(start, i-start+1));

            //for backtracking remember to use i and not i+1 as reusing of elements is allowed
            backtrack(global_result, local_result, s, i+1);
            local_result.pop_back();
        }
    }
}



public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0) return vector<vector<string>>();
        vector<vector<string>> gr;
        vector<string> lr;
        
        backtrack(gr, lr, s, 0);
        return gr;
        
    }
};
