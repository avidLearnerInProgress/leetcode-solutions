class Solution {
/*

Based on general solution of backtracking - https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)

*/
private:
    void backtrack(vector<vector<int>> &global_result, vector<int> &local_result, vector<int> &candidates, int start, int remaining) {
        
        if(remaining < 0) return;
        if(remaining == 0) {
            
            global_result.push_back(local_result);
        }
        
        for(int i=start; i<candidates.size(); i++) {
            local_result.push_back(candidates[i]);
            
            //for backtracking remember to use i and not i+1 as reusing of elements is allowed
            backtrack(global_result, local_result, candidates, i, remaining - candidates[i]);
            local_result.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            
        if(candidates.size() == 0) return vector<vector<int>>();
        vector<vector<int>> gr;
        vector<int> lr;
        
        sort(candidates.begin(), candidates.end());
        // candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        backtrack(gr, lr, candidates, 0, target);
        return gr;
    }
};
