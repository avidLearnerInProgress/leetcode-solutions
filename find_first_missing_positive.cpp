class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int tofind = 1;
        while(1){   
            if(find(nums.begin(), nums.end(), tofind) == nums.end())
                return tofind;
            tofind++;
        }
        return -1;
    }
};