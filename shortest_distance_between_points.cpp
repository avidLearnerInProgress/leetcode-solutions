class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        if(distance.size() == 0) return 0;
        int res1 = 0, res2 = 0;
        
        for(int i=start; i!=destination;){
            res1 += distance[i];    
            i = (i + 1) % distance.size();
        }
        for(int i=destination; i!=start;){
            res2 += distance[i];    
            i = (i + 1) % distance.size();
        }
        return min(res1, res2);
    }
};