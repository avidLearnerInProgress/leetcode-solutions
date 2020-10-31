class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        make_heap(nums.begin(), nums.end());
        for(auto i=0; i<k-1;i++) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};      
