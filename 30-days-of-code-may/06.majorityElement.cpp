class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        map<int, int> hash;
        for(auto num : nums)
            hash[num]++;
        int sz = nums.size();
        
        for(auto const& p : hash){
            if(p.second > sz/2){
                return p.first;
            }
        }
        return -1;
    }
};