class Solution {
public:
    
    void swap(char &x, char &y){
        auto t = x;
        x = y;
        y = t;
    }
    
    string reverseOnlyLetters(string S) {
        
        if(S.size() == 0) return "";
        
        int i = 0, j = S.size() - 1;
        
        
        while(i <= j){
            
            if(isalpha(S[i]) and isalpha(S[j]))
                swap(S[i], S[j]);
            
            else if(!isalpha(S[i])){
                i++; continue;
            }
            else if(!isalpha(S[j])){
                j--; continue;
            }
        
            i++; j--;
        }
        return S;
    }
};  
