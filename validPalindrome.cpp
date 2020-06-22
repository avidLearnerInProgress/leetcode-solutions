class Solution {
public:
    bool checkPalin(string s, int i, int j){
        
        while(i<=j){
            if(s[i] == s[j]){
            i+=1; j-=1;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.empty()) return false;
        
        int i = 0, j = s.size() - 1;
        
        //2 cases
        // even length palindrome or odd length palindrome
        
        while(i <= j){
            
            if(s[i] != s[j]){
                return checkPalin(s, i, j-1) or checkPalin(s, i+1, j); 
            }
            else{
                i+=1;
                j-=1;
            }
        }
        return true;
    }
};
