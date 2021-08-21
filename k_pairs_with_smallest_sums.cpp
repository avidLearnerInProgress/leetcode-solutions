class Solution {
    struct compare {
        bool operator()(const vector<int> &p1, const vector<int> &p2) {
            return p1[0] + p1[1] > p2[0] + p2[1];
        }
    };
    
public:

    // TC: O(m * n * log k) | SC : O(k) ==> Results in TLE for larger testcases
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;
//         int m = nums1.size(), n = nums2.size();
        
//         for(int r = 0; r < m; ++r) {
//             for(int c = 0; c < n; ++c) {
//                 maxHeap.emplace(nums1[r], nums2[c]);
//                 if(maxHeap.size() > k) maxHeap.pop();
//             }
//         }
        
//         vector<vector<int>> result;
//         while(!maxHeap.empty()) {
//             auto &[f, s] = maxHeap.top();
//             result.push_back({f, s});
//             maxHeap.pop();
//         }
        
//         return result;
//     }
    
    
    
    //TC : O(k * logk) | SC: O(k)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<vector<int>, vector<vector<int>>, compare> minHeap;
        int m = nums1.size(), n = nums2.size();
        
        for(int r = 0; r < min(m, k); ++r) { //very similar optimization as mentioned here - 
            minHeap.push({nums1[r], nums2[0], 0});
        }
        
        vector<vector<int>> result;
        while(k-- and !minHeap.empty()) {
            auto &top = minHeap.top();
            int n1 = top[0], n2 = top[1], colIdx = top[2];
            minHeap.pop();
            result.push_back({n1, n2});
            if(colIdx + 1 < n) {
                int newColIdx = colIdx + 1;
                minHeap.push({n1, nums2[newColIdx], newColIdx});
            }            
        }
        return result;
    }
};
