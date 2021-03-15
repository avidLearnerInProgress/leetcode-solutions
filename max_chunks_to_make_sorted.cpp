class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int max_ = 0, result = 0;
        //we find the max_seen_so_far
        //and if max_seen_so_far == current_index, we can divide the array in one chunk.
        
        for(int i=0; i<arr.size(); i++) {
            max_ = max(max_, arr[i]);
            if(max_ == i) result++;
        }
        
        return result;
    }
}; 
