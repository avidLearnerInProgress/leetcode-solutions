class Solution {
public:
   int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        // 1. find the first i where nums[i] < nums[j] && i > j; start = j
        // 2. find the last i where nums[i] > nums[j] && i < j; end = j
        // ans = end - start + 1;
        
        // start and end are set this way so that by default, ans = end - start + 1 = 0
        int start = 0, end = -1;
        
        // 1. find the first i where nums[i] < nums[j] && i > j; start = j
        int min_ = INT_MAX;
        for (int i = 0; i < n; i++) 
            if (nums[n-i-1] <= min_) min_ = nums[n-i-1];
            else  start = n-i-1;
        
        // 2. find the last i where nums[i] > nums[j] && i < j; end = j
        int max_ = INT_MIN;
        for (int i = 0 ; i < n; i++)
            if (nums[i] >= max_) max_ = nums[i];
            else end = i;
    
        return end - start + 1;
    }
};
