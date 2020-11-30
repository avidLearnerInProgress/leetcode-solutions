class Solution:
    int singleNumber(vector<int> &nums){
        int x = 0;
        for(auto num : nums) x ^= num;
        return x;
    }
};
