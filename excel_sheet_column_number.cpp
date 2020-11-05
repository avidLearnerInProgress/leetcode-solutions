class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        
        for(auto c : s) {
            int decimal = c - 'A' + 1; //convert 0 based indexing to 1 based indexing hence added once
            result = result * 26 + decimal;
        }
        
        return result;
    }
};
