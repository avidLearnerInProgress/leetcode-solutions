class Solution {
    
    struct Comp {
      bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
          int distance1 = p1.first*p1.first + p1.second*p1.second;
          int distance2 = p2.first*p2.first + p2.second*p2.second;
          return distance1 < distance2;
      }  
    };
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> maxHeap;
        
        for(auto &point : points) {
            maxHeap.push({point[0], point[1]});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            auto top = maxHeap.top();
            result.push_back({top.first, top.second});
            maxHeap.pop();
        }
        return result;
    }
};
