class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        
        
        //sort the array by difference
        sort(costs.begin(), costs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] - v1[1] < v2[0] - v2[1];
        });
        
        //positive difference have 0th element > 1st element
        //negative difference have 1st element > 0th element
        
        for(auto cost : costs)
            cout<<cost[0]<<"\t"<<cost[1]<<"\n";
        
        int minCost = 0;
        
        //greedily pick the 0th element from first n/2 elements
        for(int i=0; i<costs.size(); i++){
            if(i<costs.size()/2)
                minCost += costs[i][0];
            else
                minCost += costs[i][1];
        }
        return minCost;
    }
};