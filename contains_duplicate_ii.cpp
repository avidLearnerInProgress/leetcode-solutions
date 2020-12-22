class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> ump;
        for(int i=0; i<nums.size(); i++) {
            
            if(ump.find(nums[i]) != ump.end() and abs(i - ump[nums[i]]) <= k) return true;
            ump[nums[i]] = i;
            
        }
        
        return false;
    }
};
