class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int empty = 0;
        int result = 0;
        int idx1 = -1, idx2 = -1;
        
        for(int i = 0; i < n; ++i){
            if(seats[i] == 1){ //internal seats 
                empty = 0;
                if(idx1 == -1) idx1 = i; //pick the first 1(1 from start) in the array
                idx2 = i; //pick the second 1 in the array
            } else { //external seats 
                empty++;
                result = max(result, (empty+1)/2);
            }
        }
        result = max({result, idx1, n-1-idx2}); //max among all of them
        return result;
    }
};
