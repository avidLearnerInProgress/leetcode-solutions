class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;
        
        for(int num : nums){
            if(num != 0){
                nums[j++] = num;
            }
        }
        
        for(; j<nums.size(); j++){
            nums[j] = 0;
        }
    }
};