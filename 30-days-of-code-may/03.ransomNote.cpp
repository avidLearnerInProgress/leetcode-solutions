
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<int,int> mp;
        
        for(char m : magazine)
            mp[m-'a']++;
        
        for(char r : ransomNote){
            if(--mp[r-'a'] < 0)
                return false;
            
        }
        return true;
    }
};