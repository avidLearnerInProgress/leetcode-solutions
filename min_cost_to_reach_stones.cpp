/*
Adopted from here - https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/675912/DP-code-decoded-for-non-experts-like-me
*/
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
      // 1. check for feasibility
      int N = stones.size(); if ((N-1) % (K-1) != 0) return -1;
      // calculate partial sums
      vector<int> p(N+1);
      for (int i = 0; i < N; i++)
        p[i+1] = p[i] + stones[i];
      
      // 2. populate dp
      vector<vector<int>> dp(N, vector<int>(N));
      // len is the current substring we are processing (sub-problem)
      for (int len = K; len <= N; len++) {
        // i and j are the span of the previous sub-problems, we are scanning over
        for (int i = 0; i <= N-len; i++) {
          int j = i+len-1;
          dp[i][j] = INT_MAX;
          // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
          for (int mid = i; mid < j; mid+=K-1) {
            dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
          }
          if ((j-i) % (K-1) == 0) 
            dp[i][j] += p[j+1] - p[i];
        }
      }
      // 3. return result
      return dp[0][N-1];
        
    }
};
