class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        //my approach
        unordered_map<int, vector<pair<int, int> > >hash;
        queue<vector<int> >q;
        int result = INT_MAX;
        int cnt = 0;
        for (auto item : a) {
            hash[item[0]].push_back(make_pair(item[1], item[2]));
            if (item[0] == src) q.push({item[0], item[1], item[2]});
        }
        while (!q.empty()) {
            if (cnt == k + 1) break;
            for (int i = q.size(); i > 0; --i) {
                vector<int> node = q.front(); q.pop();
                if (node[1] == sink) result = min(result, node[2]);
                if (node[2] > result) continue;
                for (int j = 0; j < hash[node[1]].size(); ++j) {
                    q.push({node[1], hash[node[1]][j].first, node[2] + hash[node[1]][j].second});
                }
            }
            ++cnt;
        }
        return result == INT_MAX ? -1 : result;
        
        //best solution
        /*vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];*/
    }
};