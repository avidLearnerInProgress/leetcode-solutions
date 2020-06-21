class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int mid, low = 0, high = nums.size() - 1;
        int midEle, cLeft, cRight;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            
            if(nums[mid] == target) return mid;

            //right half is sorted
            if(nums[mid] <= nums[high]){
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            
            //left half is sorted
            else{
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};