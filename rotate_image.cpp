class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        //1. transpose matrix
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //2.swap columns with 2 pointer approach
        
        for(int i=0; i<N; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};