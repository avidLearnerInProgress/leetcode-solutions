class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> combination;
        combine(output, combination, n, k, 1);
        return output;
    }

private:
    void combine(vector<vector<int>>& output, vector<int> combination, int n, int k, int i) {
        if (combination.size() == k) {
            output.push_back(combination);
            return;
        }
        for (int j = i; j <= n; j++) {
            combination.push_back(j);
            combine(output, combination, n, k, j + 1);
            combination.pop_back();
        }
    }
};
