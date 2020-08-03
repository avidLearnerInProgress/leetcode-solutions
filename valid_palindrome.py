class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        stt = []
        for st in s:
            if st >= 'a' and st <= 'z' or st >= '0' and st <= '9':
                stt.append(st)
        print(stt)
        i = 0; j = len(stt) - 1
        
        while(i <= j):
            if stt[i] != stt[j]:
                return False
            i += 1
            j -= 1
        return True
    
'''
CPP solution -

class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.length() == 0) return true;
        
        int m=s.length()-1;
        int i=0;
        
        while(i<m) {
            
            if(isalnum(s[i]) && isalnum(s[m])) {
                if(tolower(s[i]) != tolower(s[m]))
                    return false;
                else{
                    i++, m--;
                    continue;
                }
            } 
            else {
                if(!isalnum(s[i])) i++;
                if(!isalnum(s[m])) m--;
            }
        }
        return true;   
    }
};
    '''
