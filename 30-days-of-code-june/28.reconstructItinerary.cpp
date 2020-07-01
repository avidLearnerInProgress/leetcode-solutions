class Solution {
//BEST1: post-order traversal + ordered set
public: 
    // Time/Space: O(NlogN), O(N)
    vector<string> findItinerary(vector<vector<string> >& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string> > m;  //this is how to represent the graph        
        for (auto& a : tickets)  m[a[0]].insert(a[1]);
        string start("JFK");
        dfs(m, start, res);  //post-order traversal
        //return vector<string> (res.rbegin(), res.rend()); // ok
        return {res.rbegin(), res.rend()}; // better
    }
    
    void dfs(unordered_map<string, multiset<string> > &m, string& s, vector<string> &res) {    
        while (m[s].size()) {
            auto cur = m[s].begin();
            string t = *cur;
            m[s].erase(cur);  //cur ticket is used, so need to be removed
            dfs(m, t, res);
        }
        res.emplace_back(s); // since the root info is consumed in the last, so this is post-order traversal
    }
};
