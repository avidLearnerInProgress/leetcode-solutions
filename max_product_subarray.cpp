class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
		int result = nums[0];
		int curr_max = nums[0];
		int curr_min = nums[0];
		for (int i = 1; i < n; i++) {
			int curr_max_prev = curr_max;
			curr_max = max(nums[i], max(curr_max * nums[i], curr_min * nums[i]));
			curr_min = min(nums[i], min(curr_max_prev * nums[i], curr_min * nums[i]));
			result = max(result, curr_max);
		}
		return result;
    }
};

