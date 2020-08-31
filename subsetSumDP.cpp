#include<bits/stdc++.h>
using namespace std;


bool isSubSetSumRecursiveHelper(vector<int> v, int target, int n) {
    if(n <= 0 || target < 0) return false;
    if(target == 0) return true;
    
    bool include = isSubSetSumRecursiveHelper(v, target - v[n], n - 1);
    bool exclude = isSubSetSumRecursiveHelper(v, target, n - 1);
    return include || exclude;
}


bool isSubSetSumRecursive(vector<int> v, int target) {
    if(v.size() == 0) return false;
    
    //pick last element or dont pick;
    return isSubSetSumRecursiveHelper(v, target, v.size() - 1);
    
}



unordered_map<string, int> mp;
bool isSubsetSumMemoizedHelper(vector<int> v, int target, int n) {
    
    if(n <= 0 || target < 0) return false;
    
    if(target == 0) return true;
    
    string key = to_string(n) + '|' + to_string(target);
    if(mp.find(key) == mp.end()) {
        bool include = isSubsetSumMemoizedHelper(v, target - v[n], n - 1);
        bool exclude = isSubsetSumMemoizedHelper(v, target, n - 1);
        mp[key] = target;
        
        return include || exclude;
    }
    //else already found;
    return mp[key];
}


bool isSubsetSumMemoized(vector<int> v, int target) {
    if(v.size() == 0) return false;
    return isSubsetSumMemoizedHelper(v, target, v.size() - 1);
}


bool isSubsetSumDP(vector<int> v, int target) {
    if(v.size() == 0) return false;
    
    int n = v.size();
    int dp[n + 1][target + 1];
    
    for(int i=0; i<=n; i++) {
        dp[0][i] = false;
    }
    
    for(int j=0; j<=target; j++) {
        dp[j][0] = true;
    }
    
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=target; j++) {
            
            if(v[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                //include || exclude
                dp[i][j] = dp[i-1][j] || dp[i-1][j - v[i-1]];
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    cout<<isSubSetSumRecursive({1,2,3,4,5,6,7,8}, 7);
    
    cout<<isSubsetSumMemoized({1,2,3,4,5,6,7,8}, 7);
    
    cout<<isSubsetSumDP({1,2,3,4,5,6,7,8}, 7);
}
