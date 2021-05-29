class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        for(auto num : nums) sum += num;
        
        sum -= x;
        if(sum == 0) return nums.size();
        
        
        int low = 0, cur = 0, mid = 0;
        for(int high = 0 ; high < nums.size(); high++) {
            cur += nums[high];
            while(sum < cur and low < nums.size()) 
                cur -= nums[low++];
            
            if(sum == cur)
                mid = max(mid, high - low + 1);
            
        }
        
        return (mid == 0) ? -1 : nums.size() - mid;
    }
};
