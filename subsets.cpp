class Solution {
    
private:
    
    
    void backtrack(vector<vector<int>> &global_result, vector<int> &local_result, vector<int>& nums, int start) {
        global_result.push_back(local_result);
        for(int i=start; i<nums.size(); i++) {
            local_result.push_back(nums[i]);
            backtrack(global_result, local_result, nums, i+1);
            local_result.pop_back();
        }        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();
        vector<vector<int>> global_result;
        vector<int> local_result;

        backtrack(global_result, local_result, nums, 0);
        return global_result;
        
    }
};
