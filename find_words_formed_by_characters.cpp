class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> mp(26), tmp(26);
        
        for(auto s:chars)
            mp[s - 'a']++;
        
        tmp = mp;
        auto result = 0;
        
        for(auto w:words){
            
            mp = tmp;
            bool flag = true;
            
            for(auto i:w){    
                if(mp[i-'a'] == 0){
                    flag = false;
                    break;
                }
                else
                    mp[i - 'a']--;
            }
            if(flag)
                result += w.size();       
        }
        return result;
    }
};