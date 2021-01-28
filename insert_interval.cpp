class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(newInterval.empty()) return intervals;
        
        vector<vector<int>> result;
        for(auto interval : intervals) {
            
            //before the range
            if(newInterval[1] < interval[0]) {
                result.push_back(newInterval);
                newInterval = interval;
            }
            
            //after the range
            else if(newInterval[0] > interval[1]) {
                result.push_back(interval);
            }
            
            
            //overlap .. min start, max end
            else if(newInterval[1] > interval[0] || newInterval[0] < interval[1]) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }            
        }

        result.push_back(newInterval);
        return result;
    }
};
