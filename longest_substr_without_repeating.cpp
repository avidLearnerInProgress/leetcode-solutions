class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        
        unordered_map<char, int> ump;
        int start = 0, longest = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(ump.find(s[i]) != ump.end() and ump[s[i]] >= start) {
                start = ump[s[i]] + 1;
            }
            ump[s[i]] = i;
            longest = max(longest, i - start + 1);
        }
        
        return longest;
    }
};
