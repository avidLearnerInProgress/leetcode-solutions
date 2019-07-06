class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0; i<=num; i++){
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
    
};