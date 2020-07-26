class Solution {
public:
    int findMin(vector<int>& nums) {
         return *min_element(begin(nums),end(nums));
    }
};
