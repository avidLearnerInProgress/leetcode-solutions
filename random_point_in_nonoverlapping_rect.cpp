class Solution {
    vector<vector<int>> rect;
    vector<int> area;
    int n,tarea;
public:
    Solution(vector<vector<int>>& rects) {
        n = rects.size();
        this->rect = rects;
        for(int i=0;i<n;i++){
            
            int x1 = rects[i][0], x2 = rects[i][2];
            int y1 = rects[i][1], y2 = rects[i][3];
            int dx = x2-x1+1, dy = y2-y1+1;
            int a = abs(dx*dy);
            i==0?area.push_back(a):area.push_back(a+area[i-1]);
        }
        tarea = area[n-1];
    }
    
    vector<int> pick(){
        int randArea = rand()%tarea;
        int idx = upper_bound(area.begin(),area.end(),randArea) - area.begin();
        int x1 = rect[idx][0], x2 = rect[idx][2];
        int y1 = rect[idx][1], y2 = rect[idx][3];
        int dx = x2-x1+1, dy = y2-y1+1;
        int X = x1 + rand()%dx;
        int Y = y1 + rand()%dy;
        return {X,Y};
        
    }
};
