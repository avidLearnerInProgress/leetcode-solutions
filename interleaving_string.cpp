class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.size(), n = s2.size();
        if(m + n != s3.size()) return false;
        bool T[m+1][n+1];
        memset(T, 0, sizeof(T));
        T[0][0] = true;

        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 and j==0) T[i][j] = true;
                
                else if(i == 0) {
                    if(s1[i-1] == s3[i-1]) T[i][j] = T[i][j-1];
                }  
                
                else if(j == 0) {
                    if(s2[j-1] == s3[j-1]) T[i][j] = T[i-1][j];
                }
                
                else if(s2[j-1] == s3[i+j-1] and T[i-1] != s3[i+j-1] and s1[i-1] == s3[i+j-1]) T[i][j] = T[i][j-1] || T[i-1][j];
                else if(s1[i-1] == s3[i+j-1] and T[j] != s3[i+j-1]) T[i][j] = T[i-1][j];
                else if(T[j] and s2[i-1] == s3[i+j-1]) T[i][j] = T[i][j-1];
            }
        }
        return T[m][n];
        
    }
};
