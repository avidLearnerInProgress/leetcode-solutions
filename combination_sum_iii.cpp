class Solution {
    
//Solution based on https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
    
//combinations - global_result, combination - local_result
private:
    void backtrack(vector<vector<int>> &combinations, vector<int> &combination, vector<int> numbers, int k, int n, int start, int sum) {
        
        if(k == 0 and sum == n) {
            combinations.push_back(combination);
        }
        
        else {
            
            for(int i=start; i<numbers.size(); i++) {
                
                combination.push_back(numbers[i]);
                backtrack(combinations, combination, numbers, k-1, n, i+1, sum + numbers[i]);
                combination.pop_back();
            }
            
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> combinations;
        vector<int> combination;
        vector<int> numbers = {1,2,3,4,5,6,7,8,9};
        
        backtrack(combinations, combination, numbers, k, n, 0, 0);
        
        return combinations;
    }
};
