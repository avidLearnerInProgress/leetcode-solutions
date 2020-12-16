class Solution {
    
private:
        void backtrack(vector<vector<int>> &global_result, vector<int> &local_result, vector<int> &nums, vector<bool> &visited) {
            
            if(local_result.size() == nums.size()) {
                global_result.push_back(local_result);
            } 
            
            for(int i=0; i<nums.size(); i++) {
            
                if(visited[i] or (i > 0 and nums[i] == nums[i-1] and visited[i-1])) continue;
                
                local_result.push_back(nums[i]); 
                visited[i] = true;
                
                backtrack(global_result, local_result, nums, visited);
                
                local_result.pop_back();
                visited[i] = false;
                
            }
            
        }
    
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            if(nums.size() == 0) return vector<vector<int>>();
            vector<vector<int>> gr;
            vector<int> lr;
            vector<bool> visited(nums.size(), false);
            sort(nums.begin(), nums.end());
            backtrack(gr, lr, nums, visited);
            return gr;    
    }
};
