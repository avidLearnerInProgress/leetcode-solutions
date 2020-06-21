class Solution {
public:
    string frequencySort(string s) {
        if(s.length() == 0) return "";
        
        /*
        vector<int> frequency(256, 0);
        for(auto c : s) frequency[c]++;
        sort(s.begin(), s.end(), [&](const char &A, const char &B){
            return frequency[A] > frequency[B] || (frequency[A] == frequency[B] && A < B);
        });
        
        */
        
        unordered_map<char, int> ump;
        vector<pair<int, char>> vtr;
        
        
        for(auto c:s) ump[c]++;
        
        for(auto it = ump.begin(); it != ump.end(); it++)
            vtr.push_back({it->second, it->first});
        
        sort(vtr.begin(), vtr.end());
        string res = "";
        
        for(int i=0; i<vtr.size(); i++){
            res.append(vtr[i].first,vtr[i].second);
        }
        cout<<res[1];
        reverse(res.begin(), res.end());
        return res;
    }
};