class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int start = 0, end = nums.size() - 1, mid;      
        while(start < end){
            mid = start + (end - start) / 2;
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid+1]) start = mid + 2;
                else if(nums[mid] == nums[mid-1]) end = mid - 2;
                else return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid-1]) start = mid + 1;
                if(nums[mid] == nums[mid+1]) end = mid - 1;
            }
        }
        return nums[start];
    }
};