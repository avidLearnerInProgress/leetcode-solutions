class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0) return false;
        auto capital = 0;
        auto flag = false;
        if(word[0] >= 'A' and word[0] <= 'Z') flag = true;
        
        for(auto i=1; i<word.size(); i++) {
            if(word[i] >= 'A' and word[i] <= 'Z') capital++;
        }
        //if(capital < word.size()-1 and flag == true) return false;
        if((capital == 0) or (capital == word.size()-1 and flag == true)) return true;
        return false;
    }
};
