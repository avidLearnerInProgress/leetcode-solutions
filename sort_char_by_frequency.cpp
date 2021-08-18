// class Solution {
// public:
//     string frequencySort(string s) {
//         if(s.length() == 0) return "";
        
//         /*
//         vector<int> frequency(256, 0);
//         for(auto c : s) frequency[c]++;
//         sort(s.begin(), s.end(), [&](const char &A, const char &B){
//             return frequency[A] > frequency[B] || (frequency[A] == frequency[B] && A < B);
//         });
        
//         */
        
//         unordered_map<char, int> ump;
//         vector<pair<int, char>> vtr;
        
        
//         for(auto c:s) ump[c]++;
        
//         for(auto it = ump.begin(); it != ump.end(); it++)
//             vtr.push_back({it->second, it->first});
        
//         sort(vtr.begin(), vtr.end());
//         string res = "";
        
//         for(int i=0; i<vtr.size(); i++){
//             res.append(vtr[i].first,vtr[i].second);
//         }
//         cout<<res[1];
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

class Solution {
    struct Comp {
      bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
          if(l.first != r.first) {
              return l.first < r.first;
          }
          return l.second > r.second;
      }  
    };
public:
    string frequencySort(string s) {
        if(s.empty()) return s;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Comp> Q; 
        unordered_map<int, int> count;
        
        for(const char &c : s) 
            count[c]++;
        
        for(auto &[k, v] : count) {
            Q.emplace(v, k);
        }
        
        string result = "";
        while(!Q.empty()) {
            int frequency = Q.top().first;
            while(frequency--)
                result += Q.top().second;
            Q.pop();
        }
        return result;
    }
};
