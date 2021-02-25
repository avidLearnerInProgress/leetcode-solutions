class Solution {
public:
    char dp[101][101][27][101];
    int getLen(int n){
        if(n < 1) 
            return 0;
        if(n < 10)
            return 1;
        if(n < 100)
            return 2;
        return 3;
    }
    /*
    indx - current index
    k - remaining maximum number of characters that can be removed
    last - last taken character
    cum - how many consucutive `last` character has been taken till now
    */
    char call(int indx, int k, int last, int cum, string &s){
        if(indx == s.size())
            return getLen(cum) + (cum>1); // get length and add 1 for the character itself only if length > 1. eg. cum=15 will return 3 from here.
        char &ret = dp[indx][k][last][cum];
        if(~ret) return ret;
        int nextCum = last == (s[indx]-'a')? cum+1:1; // if current character is same as last one, do cum+1, otherwise start new count (1) from here
        ret = call(indx+1, k, s[indx]-'a', nextCum, s) + (nextCum == 1?getLen(cum) + (cum>1):0); // Here we consider taking current character, 
		// if it matches the last character, do cum+1
        // otherwise we init cum=1, and this s[indx] becomes new `last` character

        if(k)
            ret = min(ret, call(indx+1, k-1, last, cum, s)); // if we still have choice to skip some character, we try to skip one here, 
			// in that case last and cum remain same as before.
        return ret;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return call(0, k, 26, 0, s);
    }
};
