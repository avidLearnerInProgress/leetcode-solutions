class Solution {
public:
    int min(int a, int b){
        if(a<b) return a;
        return b;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        int res = 0;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0) continue;
                
                if(i == 0 || j == 0){
                    res++;
                    continue;
                }
                matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
                res += matrix[i][j];
            }
        }
        return res;
    }
};