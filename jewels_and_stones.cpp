class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J == "") return 0;
        if(S == "") return 0;
        
        int ct = 0;
        for(auto const &n : J){
            ct += count(S.begin(), S.end(), n);
        }
        return ct;
    }
};