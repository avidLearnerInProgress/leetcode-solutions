class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return 0;
        int count = 1;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] >= end) { //next's start is greater than previous end time
                end = intervals[i][1];
                count++;
            }   
        }
        return intervals.size() - count;
    }
};
