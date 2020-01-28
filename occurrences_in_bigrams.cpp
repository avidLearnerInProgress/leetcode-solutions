class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        string F = "", S = "";
        string word;
        vector<string> ans;
        
        for(char c : text){
            if(c == ' '){        
                if(F == first && S == second) ans.push_back(word);
                F = S;
                S = word;
                word.clear();
            }
            else
                word.push_back(c);
        }
        if(F == first && S == second) ans.push_back(word);
        return ans;
    }
};