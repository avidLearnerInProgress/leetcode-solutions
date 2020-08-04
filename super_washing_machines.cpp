class Solution {
public:
    int max(int a, int b) {
        return a >= b ? a : b;
    }
    
    int findMinMoves(vector<int>& machines) {
        if(machines.size() == 0) return 0;
        auto total_dresses = accumulate(machines.begin(), machines.end(), 0);
        cout<<total_dresses;
        
        if(total_dresses % machines.size() != 0) return -1; //not possible to completely divide the load of machines
        auto average_load = (int) total_dresses / machines.size();
        auto peak_load = 0, max_load = 0;
        for(const auto load : machines) {
            peak_load += load - average_load;
            max_load = max((load - average_load), max(abs(peak_load), max_load));
        }
        return max_load;
    }
};
