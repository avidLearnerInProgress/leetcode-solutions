class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int total_delta = 0, delta = 0;
        int start = 0, i = 0;
        
        while(i < n) {
            total_delta += gas[i] - cost[i];
            delta += gas[i] - cost[i];
            
            if(delta < 0) {
                delta = 0;
                start = i + 1;
            }
            i++;
        }
        
        if(total_delta < 0) return -1;
        else return start;
    }
};					
