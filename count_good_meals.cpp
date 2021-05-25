class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        
        /*
        
        x + y = 2^z
        y = 2^z - x where, y < x
        modification to 2sum with sum in range(pow(2, i)) where 0 <= i <= 21
        */
        
        unordered_map<int, int> frequency;
        sort(deliciousness.begin(), deliciousness.end()); //without this y < x doesnt hold true.
        
        int ans = 0;
        int mod = 1e9 + 7;
        
        for(auto &x : deliciousness) {
            for(int j = 0; j < 22; j++) {
                
                int y = (1<<j) - x;
                if(y > x) break; //without this TLE.. addition is commutative(x + y), need to enforce y < x for x + y = 2^z
                else if(frequency.find(y) != frequency.end()) {
                    ans = (ans + frequency[y]) % mod;
                }
            }
            frequency[x]++;
        }
        return ans;
    }
};
