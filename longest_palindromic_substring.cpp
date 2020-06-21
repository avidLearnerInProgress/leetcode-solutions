class Solution {

private:
    string helper(string s, int begin, int end) {
        if(s.empty()) return NULL;
        if(end >= s.size()) return "";
        
        while((begin >= 0 and end <= s.length()-1) and (s[begin] == s[end])) {
            begin--; end++;
        }
        return s.substr(begin+1, end - begin - 1); //length of current palindromic substr
    }
    
public:
    string longestPalindrome(string s) {
        
        /*palindromic substrings can be either even length or odd length..
        
        to find palindromes.. start from middle of substring and and expand the window on both the ends..
        
         */
        if(s.length() == 1 or s == "") return s;
        
        string curr = "";
        //int maxLen = globalMax.length();
        
        for(int i=0; i<s.size(); i++){
            string tmp = helper(s, i, i); // for odd length strings..
            //maxLen = max(maxLen, oddLength.length());
            if(tmp.size() > curr.size()){
                curr = tmp;
            }
            tmp = helper(s, i, i+1); // for even length strings
            //maxLen = max(maxLen, evenLength.length());
            if(tmp.size() > curr.size()){
                curr = tmp;
            }
            
        }
        return curr;
    }

};