class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return vector<vector<int>>();
        vector<vector<int>> result;   
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        //sort by start of each interval
        //now check if end of current interval is <= start of next interval
        // [[1, 2], [1, 6]] ==> [here 1 in second is < end of first] !!
        // if current_interval_end < next_interval_start := there is overlap
        //      set current_interval_end as max between current_end and next_end
        // else := no overlap
        //      set current_interval as ith interval
        //      add current_interval to result
        
        auto current_interval = intervals[0];
        
        for(auto i=0; i<intervals.size(); i++) {
            auto current_begin = current_interval[0];
            auto current_end = current_interval[1];
            auto next_begin = intervals[i][0];
            auto next_end = intervals[i][1];
            
            if(next_begin <= current_end){
                current_interval[1] = max(current_end, next_end);
                cout<<current_interval[0]<<" "<<current_interval[1];     
            }
            else { // just merge as it is..
                result.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        result.push_back(current_interval);
        return result;
    }
};
