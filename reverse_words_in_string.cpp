class Solution {
public:
    string reverseWords(string s) {
       
        string result = "";
        int i = 0, N = s.length();
        
        while(i < N) {
            while(i < N && s[i] == ' ') i++;
            if(i >= N) break;
    
            int j = i + 1;
            
            while(j < N && s[j] != ' ')
                j++;
            
            string substr = s.substr(i, j-i);
            if(result.length() == 0) {
                result = substr;
            }
            else result = substr + " " + result;
            i = j + 1;
        }
        
        return result;
    }
};
