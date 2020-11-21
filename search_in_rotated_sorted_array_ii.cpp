class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return false;
        
        int mid, left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            
            mid = left + (right - left) / 2;
            
            if(nums[mid] == target) return true;
            
            if(nums[mid] == nums[left] and nums[mid] == nums[right]) {
                left++, right--;
            }
            else if(nums[left] <= nums[mid]) {
                if(nums[left] <= target and target < nums[mid]) {
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            else {
                if(nums[mid] < target and target <= nums[right]) {
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return false;
    }
};
