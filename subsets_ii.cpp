class Solution {
    
private:
    void backtrack(vector<vector<int>> &global_result, vector<int> &local_result, vector<int>& nums, int start) {
        global_result.push_back(local_result);
        for(int i=start; i<nums.size(); i++) {
            if(i > start and nums[i] == nums[i-1]) continue;
            local_result.push_back(nums[i]);
            backtrack(global_result, local_result, nums, i+1);
            local_result.pop_back();
        }        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> gr;
        vector<int> lr;
        sort(nums.begin(), nums.end());
        backtrack(gr, lr, nums, 0);
        return gr;
    }
};
