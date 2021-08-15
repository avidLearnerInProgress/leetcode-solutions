class Solution {
    
    //here we use < because the priority queue in cpp stl is a max heap. so to achieve true functionality or in other words to achieve the case when first element will be greater than the second, we put lhs.first < rhs.first - this means that logically this condition will hold true they will be greater.
    
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
        vector<pair<int, string>> V;
        for (auto it : cnt) {
            Q.push({it.second, it.first});
            V.emplace_back(it.second, it.first);
        }
        
        //using same custom comparator to test on Priority Queue 
        while(!Q.empty()) {
            cout<<Q.top().first<<" "<<Q.top().second<<"\n";
            Q.pop();
        }
        cout<<"---- \n\n\n ---\n";
        
        //using same custom comparator to test on Vector 
        sort(V.begin(), V.end(), [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });
        
        for(auto &ele : V) {
            cout<<ele.first<<" "<<ele.second<<"\n";
        }
        
        /* output =>
        3 abc
        2 i
        2 love
        1 coding
        1 leetcode
        ---- 


         ---
        1 leetcode
        1 coding
        2 love
        2 i
        3 abc
        
        */
        
        vector<string> res;
        
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};
