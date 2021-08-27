class Solution {
    vector<pair<char, int>> compressString(string &s) {
        vector<pair<char, int>> charMap;
        unordered_map<char, int> count;
        
        char prevChar = s[0];
        for(auto &chr : s) {
            if(chr == prevChar) {
                count[chr]++;
            }
            else {
                charMap.push_back({prevChar, count[prevChar]});
                count[chr] = 1;
            }
            prevChar = chr;
        }
        charMap.push_back({prevChar, count[prevChar]});
        return charMap;
    }
    
    bool isStretchy(vector<pair<char, int>> &countS, string &word) {
            auto countW = compressString(word);
            if(countS.size() != countW.size()) return false;
            
            for(int i = 0; i < countW.size(); i++) {
                if(countS[i].first != countW[i].first) {
                    return false;
                }   
                if(!(countS[i].second == countW[i].second or countS[i].second >= max(countW[i].second, 3))) {
                    return false;
                }
            }
            return true;        
    }   
public:
    int expressiveWords(string s, vector<string>& words) {
        if(s.size() == 0) return 0;
        int count = 0;
        auto countS = compressString(s);
        for(auto &word : words) {
            if(isStretchy(countS, word)) {
                count++;
            }
        }
        return count;
    }
};
