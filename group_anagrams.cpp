class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.empty()) return {{}};
        
        map<string, vector<string>> mp;
        
        for(auto str: strs){
            int cHash[26] = {0};
            for(auto c : str)
                cHash[c-'a']++;
            string st;
            for(auto i : cHash){
                st += to_string(i) + ',';
            }
            mp[st].push_back(str);
        }
        
        vector<vector<string>> vs;
        vector<string> cvs;
        
        for(auto& [key, value] : mp){
            for(auto ele : value){
                cvs.push_back(ele);
            }
            vs.push_back(cvs);
            cvs.clear();
        }
        return vs;
    }
};