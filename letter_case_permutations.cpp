class Solution {
public:
    
    void dfs(string& S, vector<string> &permutations, int index, string path)     {
        
        if(index == S.size()){
            permutations.push_back(path);
            return;
        }
        
        if(isalpha(S[index])){
            char t1 = tolower(S[index]);
            char t2 = toupper(S[index]);
            dfs(S, permutations, index + 1, path + t1);
            dfs(S, permutations, index + 1, path + t2);
        }
        else{
            dfs(S, permutations, index + 1, path + S[index]);
        }
        
    }
    
    vector<string> letterCasePermutation(string S) {
        
        if(S.size() == 0) return {};
        vector<string> permutations;
        dfs(S, permutations, 0, "");
        return permutations;
    }
};