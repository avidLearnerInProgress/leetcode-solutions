class Solution {
public:
    bool judgeCircle(string moves) {
        int r = 0, c = 0;
        
        for(auto &move : moves) {
            if(move == 'U') r--;
            else if(move == 'D') r++;
            else if(move == 'L') c--;
            else c++;
        }
        return r == 0 and c == 0;      
    }
};
