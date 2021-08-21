class Solution {
public:
    //TC: O(r*c*log k) | SC: O(k)
    //This approach doesnt use the advantage of sorted property of rows and columns
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         if(matrix.size() == 0 or k == 0) return -1;
    
//         priority_queue<int> maxHeap;
        
//         for(int r = 0; r < matrix.size(); r++) {
//             for(int c = 0; c < matrix[r].size(); c++) {
//                 maxHeap.emplace(matrix[r][c]);
//                 if(maxHeap.size() > k) maxHeap.pop();
//             }
//         }
//         return maxHeap.top();
//     }
    
    
    //since all the rows and cols are sorted, we can observe the problems as finding kth smallest element from sorted rows using min heap
    //optimization based on this post - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise
    
    //TC: O(k * log k) | SC: O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 or k == 0) return -1;
        int m = matrix.size(), n = matrix[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<> > minHeap;
        for(int r = 0; r < min(m, k); ++r) { //min() because we always know that the kth smallest element will lie in min(total rows, kth row)
            minHeap.push({matrix[r][0], r, 0});    
        }
        
        int kthSmallest = -1;
        for(int i = 1; i <= k; ++i) {
            auto ele = minHeap.top();
            kthSmallest = ele[0];
            int r = ele[1];
            int c = ele[2];
            
            minHeap.pop();
            if(c + 1 < n) {
                minHeap.push({matrix[r][c+1], r, c+1});
            }
        }
        return kthSmallest;
    }
    
};
