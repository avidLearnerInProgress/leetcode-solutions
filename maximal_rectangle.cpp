class Solution {
public:
    int dfs(vector<vector<char>>& matrix, int i, int j){
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[i].size() or matrix[i][j] == '0')
            return 0;
        else{
            matrix[i][j] = '0';
            return 1 + dfs(matrix, i-1, j) + dfs(matrix, i+1, j) + dfs(matrix, i, j + 1) + dfs(matrix, i, j - 1);
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        auto curr_area = 0, max_area = INT_MIN;
        
        for(auto i = 0; i < matrix.size(); i++){
            for(auto j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1'){
                    curr_area = dfs(matrix, i, j);
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};