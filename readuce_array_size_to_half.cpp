class Solution {
    // struct Comp {
    //     bool operator()(const pair<int, int> &l, const pair<int, int> &r){
    //         if(l.first != r.first) {
    //             return l.first < r.first;
    //         }
    //         return l.second < r.second;
    //     }
    // };
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> count;
        for(auto ele : arr) {
            count[ele]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>> Q; //we dont care about the elements here, so we just create a default max heap
        for(auto &[k,v] : count) {
            Q.emplace(v, k);
        }
        
        int acceptable = arr.size() / 2; //k
        int currSize = 0, setSize = 0;
        while(!Q.empty()) {
            int frequency = Q.top().first;
            setSize++;
            currSize += frequency;
            if(currSize >= acceptable)
                return setSize;
            Q.pop();
        }
        return -1;
    }
};
