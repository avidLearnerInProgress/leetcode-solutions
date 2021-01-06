#include <string.h>
class Solution {
private:
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
    
public:
    int lengthOfLastWord(string s) {
        if(isspace(s[0]) and s.length() == 1) return 0;
        int cnt = 0;
        rtrim(s);
        for(int i=s.length()-1; i>=0; i--) {
            if(!isspace(s[i])) cnt++;
            else break;
        }
        return cnt;
    }
};
