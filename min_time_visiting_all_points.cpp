class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        if(points.size() == 0) return 0;
        int min_time = 0;
        for(int i=1; i<points.size(); i++){
            
            int dx = abs(points[i-1][0] - points[i][0]);
            int dy = abs(points[i-1][1] - points[i][1]);
            min_time += max(dx, dy);
        }
        return min_time;
    }
};