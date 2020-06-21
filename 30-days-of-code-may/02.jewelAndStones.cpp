class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.size() == 0 or S.size() == 0) return 0;
        
        map<char, int> stones;
        
        for(int i=0; i<S.size();i++){
            if(stones.find(S[i]) == stones.end())
                stones[S[i]] = 1;
            else
                stones[S[i]]++;
        }
        int c = 0;
        for(char j:J){
            if(stones.find(j) != stones.end()){
                c+=stones[j];
            }
        }
        return c;
    }
};