class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        for(auto i = nums.begin(); i != nums.end()-1; i++){
            if(*(i) == *(i+1))
                return *(i);
        }
        return -1;
    }
};