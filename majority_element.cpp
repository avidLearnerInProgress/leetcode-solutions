class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int candidate = 0;
        int count = 1;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[candidate] == nums[i]) count++;
            else count--;
            
            if(count == 0) { //this means that a new element is encountered
                candidate = i;
                count = 1;
            }
        }
        return nums[candidate];
    }
};
