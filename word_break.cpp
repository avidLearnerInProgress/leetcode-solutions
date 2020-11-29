class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> dict;
        for(auto &word : wordDict) dict.insert(word);
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=0; i<n; i++) {
            for(int j=i; j>=0; j--) {
                string current = s.substr(j, i-j+1); //from j pick (i-j+1) characters backwards.. 
                /*
                00 - l

                11 - e
                10 - le

                22 - e
                21 - ee
                20 - lee
                ... and so on.
                */
                
                if(dict.find(current) != dict.end()) 
                    dp[i+1] = dp[j];

                if(dp[i+1]) break;
            }    
        }
        return dp[n];
    }
};
