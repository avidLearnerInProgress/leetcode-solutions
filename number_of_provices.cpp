class Solution {
    void dfs(vector<vector<int>>& isConnected, int i, int n) {
        for(int j = 0; j < n; ++j) {
            if(isConnected[i][j]) {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                dfs(isConnected, j, n);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numProvince = 0;
        
        for(int i = 0; i < n; ++i) {
           if(isConnected[i][i]) {
               dfs(isConnected, i, n);
               numProvince++;
           }
        }
        return numProvince;
    }
};
