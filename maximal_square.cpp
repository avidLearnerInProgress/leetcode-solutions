class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> globalSum(m + 1, vector<int>(n + 1));
        
        /*for(auto i : globalSum){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }*/
        
        /*for(int i=0; i<m; i++) // first column
            globalSum[i][0] = matrix[i][0] - '0';
        
        for(int i=0; i<n; i++) //first row
            globalSum[0][i] = matrix[0][i] - '0';*/
        
        auto globalMax = 0;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                    globalSum[i][j] = matrix[i-1][j-1] == '0'? 0 : 
                (min(globalSum[i][j-1], min(globalSum[i-1][j-1], globalSum[i-1][j])) + 1);
                globalMax = max(globalMax, globalSum[i][j]);
            }
        }
        
        cout<<"\n";
        for(auto i:globalSum){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        
        return globalMax * globalMax;
        //return 0;
    }
};