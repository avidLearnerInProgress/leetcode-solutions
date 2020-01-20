class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string lcp = "";
        
        int ind = 0;
        for(char c : strs[0]){//for each character in string0
            for(int i=1; i<strs.size();i++){
                if(c != strs[i][ind]){
                    return lcp;
                } // check this for each string
            }
            lcp += c;
            ind++;
        }
        return lcp;
    }
};