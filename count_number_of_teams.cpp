class Solution {
public:
    int numTeams(vector<int>& rating) {
        if(rating.size() == 0) return 0;
        int c=0;
        for(int i=0; i< rating.size()-2; i++){
            for(int j=i+1; j< rating.size()-1; j++){
                for(int k=j+1; k<rating.size(); k++){
                    if((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) c++;
                }
            }
        }
        return c;
    }
};