class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> answer;
        helper(result, answer, k, n, 1); // Start from digit 1
        return result;
    }

    void helper(vector<vector<int>>& r, vector<int>& a, int k, int n, int digit) {
        if(k == 0) {
            if(n == 0) r.push_back(a);
            return;
        }

        for(int i = digit; i < 10; ++i) {
            a.push_back(i);
            helper(r, a, k-1, n-i, i+1); 
            a.pop_back();
        }
    }
};