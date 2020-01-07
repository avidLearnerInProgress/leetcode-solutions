#include <bits/stdc++.h>

using namespace std;

int dp[5001][5001];
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
        if(s1.length() == 0 || s2.length() == 0){
            return 0;
        }
        
        int m = s1.length(), n = s2.length();
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0; //base case 1.

                if(s1[i-1] == s2[j-1]){ // match found. check after trimming from both s1 and s2..
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                //find max of trimmed from s1 or trimmed from s2
                //dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    int result = commonChild(s1, s2);
    fout << result << "\n";
    fout.close();
    return 0;
}


/*
bullshit :- Same code failing for 6 TC in Python.
import math
import os
import random
import re
import sys

dp = [[0] * (5001) for i in range(5001)]
# Complete the commonChild function below.
def commonChild(s1, s2):
    m, n = len(s1), len(s2)
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                if dp[i-1][j] > dp[i][j-1]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i][j-1]
    return dp[m][n]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s1 = input()
    s2 = input()
    result = commonChild(s1, s2)
    fptr.write(str(result) + '\n')
    fptr.close()
*/