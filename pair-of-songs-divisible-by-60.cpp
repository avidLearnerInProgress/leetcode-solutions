class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       
        // (a + b)mod c = (a mod c + b mod c)mod c
        // (ti + tj) % 60 == 0
        // (ti % 60) + (tj % 60) % 60 = 0 or 60
        // (tj % 60) = (60 - ti % 60) % 60
   
        int hashmap[60] = {0};
        int count = 0;
       
        for(auto &ti : time) {
           
            int tj = (60 - ti % 60) % 60;
            count += hashmap[tj];
            ++hashmap[ti % 60];
        }
       
        return count;
    }
};
