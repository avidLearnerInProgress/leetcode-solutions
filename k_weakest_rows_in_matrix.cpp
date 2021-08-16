class Solution {
public:
    struct Comp {
      bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
          if(l.first != r.first) {
              return l.first > r.first;
          }
          return l.second > r.second;
      }  
    };
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if(mat.size() == 0 or k == 0) return {};
           
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp > Q;
        unordered_map<int, int> count;
        
        for(int r = 0; r < mat.size(); r++) {
            int countOnes = 0;
            for(int c = 0; c < mat[r].size(); c++) {
                if(mat[r][c] == 1) countOnes++;
            }
            count[r] = countOnes;
        }
        
        for(auto &[k, v] : count) {
            Q.emplace(v, k);
        }
        
        vector<int> result;
        while(k-- and !Q.empty()) {
            cout<<Q.top().first<<" "<<Q.top().second<<"\n";
            result.emplace_back(Q.top().second);
            Q.pop();
        }
        return result;
    }
};
