class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        
        int left = 0, right = nums.size() - 1;
        int mid, index;
        
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                right = mid - 1;
                //index = mid - 1;
            }
            else{
                left = mid + 1;
                //index = mid + 1;
            }
        }
        return left;
    }
};
