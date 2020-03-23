class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(changed) return false;
                changed = true;
                if(i > 0) {
                    if(nums[i-1] > nums[i+1]) {
                        nums[i+1] = nums[i];
                    } else {
                        nums[i] = nums[i-1];
                    }
                }
            }
        }
        return true;
        
    }
};