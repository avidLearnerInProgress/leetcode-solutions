class Solution {
    struct Comp {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
            if(p1.first != p2.first) {
                return p1.first < p2.first;
            }
            else 
                return p1.second < p2.second;
        };
    };
public:
    
    //this works but it is not the most optimal
    //TC: O(k * log k) | SC: O(k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> maxHeap;
        
        for(auto &num : arr) {
            int distance = abs(num - x);
            maxHeap.emplace(distance, num);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        vector<int> result;
        while(k-- and !maxHeap.empty()) {
            auto &[_, element] = maxHeap.top();
            result.emplace_back(element);
            maxHeap.pop();
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
