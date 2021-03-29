class Solution {
public:
    int result;
    int findLength(vector<vector<int>>& arr,vector<vector<int>>& dp,int i,int j,int prev){
        int n = arr.size();
        int m = arr[0].size();
            	//check if i and j are valid (in range) and this value is greater than prev value
        if(i<0 || j<0 || i>=n || j>=m || arr[i][j]<=prev)
            return -1;
        //already computed
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1;
        //recur for neighbours
        ans = max(ans,findLength(arr,dp,i-1,j,arr[i][j])+1);
        ans = max(ans,findLength(arr,dp,i+1,j,arr[i][j])+1);
        ans = max(ans,findLength(arr,dp,i,j-1,arr[i][j])+1);
        ans = max(ans,findLength(arr,dp,i,j+1,arr[i][j])+1);
        dp[i][j]=ans;
        //update overall result
        result = max(result,ans);
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n==0)return 0;
        int m = arr[0].size();
        result = INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                findLength(arr,dp,i,j,INT_MIN);
            }
        }
        return result;
    }
};
