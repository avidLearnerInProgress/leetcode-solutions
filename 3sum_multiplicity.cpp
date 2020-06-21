class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int mod = 1e9+7;
        unordered_map<int, int> ump;
        long res = 0;
        
        for(int i=0; i<A.size(); i++){
            res = (res + ump[target - A[i]]) % mod;
            for(auto j = 0; j<i; j++) ump[A[i] + A[j]]++;
        }
        return res;
        
        
    }
    
};