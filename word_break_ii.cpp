class Solution {
public:
    unordered_map<string, vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()) return dp[s];
        vector<string> result;
        
        for(auto w : wordDict) { //for each word in wordDict
            
            if(s.substr(0, w.length()) == w) { // find the first word in s that is in the word dict
                if(s.length() == w.length()) {
                    result.push_back(w);
                }
                
                else {
                    vector<string> suffix = wordBreak(s.substr(w.length()), wordDict);
                    for(string s : suffix) {
                        result.push_back(w + " " + s);
                    }
                }
            }
            
        }
        dp[s] = result;
        return result;
    }
};
