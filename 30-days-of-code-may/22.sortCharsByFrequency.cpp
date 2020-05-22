class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()) return "";
        map<char,int> m;
        for(auto c : s) m[c]++;
        vector<pair<int,int>> values(m.begin(),m.end());
        
        sort(values.begin(),values.end(),[](const pair<int,int>& a, const pair<int,int>& b){ 
            return a.second > b.second;
        });
        
        string result = "";
        for(auto [k, v] : values){
            while(v--){
                result.push_back(k);
            }
        }
        return result;
    }
};