class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, int> m;
        
        for(char c: s){
            m[c]++;
        }
        for(char c:t){
            if(m.find(c) != m.end())
                m[c]--;
        }
        
        for(pair<char, int> p : m){
            if(p.second != 0)
                return false;
        }
        return true;
    }
};


/*
class Solution {
public:
    bool isAnagram(string s, string t) {
     int ascii[256]={0};
        bool y =true;
        for(int i =0;s[i]!='\0';i++)++ascii[s[i]];
        for(int i =0;t[i]!='\0';i++)--ascii[t[i]];
        for(int i =0;i<256;i++){
            if(ascii[i]!=0){
                y=false;
                break;
            }
        }
        return y;
    }
};

*/