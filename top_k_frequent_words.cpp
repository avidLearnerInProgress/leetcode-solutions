class Solution {
    struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words)
            ++cnt[w];
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> Q;
        for (auto it : cnt)
            Q.push({it.second, it.first});
        
        vector<string> res;
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};
