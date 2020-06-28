class Solution {
public:
     vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        // Step 1: Store directed edges in a hash map
        unordered_map<string, multiset<string>> m;
        for (const pair<string, string> & ticket : tickets) {
            m[ticket.first].insert(ticket.second);
        }
        
        // Step 2: March greedily and traceback
        vector<string> march = { "JFK" }; // the storage for greedy searching
        vector<string> results; // store the final results reversely
        while (march.empty() == false) {
            string & from = march.back();
            if ((m.find(from) != m.end()) && (m[from].empty() == false)) { // march further
                multiset<string> & to = m[from];
                march.push_back(*(to.begin()));
                to.erase(to.begin());
            } else { // can not march further, trace back
                results.push_back(march.back()); // archive the last place
                march.pop_back();
            }
        }
        reverse(results.begin(), results.end()); // reverse the entries back
        return results;
    }
};
};
