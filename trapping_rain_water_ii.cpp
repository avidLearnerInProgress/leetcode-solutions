class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int maxx = INT_MIN;
        int visited[115][115];
        memset(visited , 0 , sizeof visited);
        int n = heightMap.size();
        if(n == 0) return 0;
        int m = heightMap[0].size();
        if(m == 0) return 0;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if((i == 0 or i == n - 1 or j == 0 or j == m -1) and !visited[i][j]){
                    visited[i][j] = 1;
                    pq.push({heightMap[i][j] , {i , j}});
                }
            }
        }
        int water = 0;
        vector<pair<int,int>> dxy = {{0,1},{1,0},{0,-1},{-1,0}};
        while(pq.empty() == false){
            int currheight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            maxx = max(maxx , currheight);
            pq.pop();
            for(int i = 0 ; i < dxy.size() ; ++i){
                int newx = x + dxy[i].first;
                int newy = y + dxy[i].second;
                if(newx < 0 or newx >= n or newy < 0 or newy >= m) continue;
                if(visited[newx][newy] == 1) continue;
                if(heightMap[newx][newy] < maxx){
                    water+= maxx - heightMap[newx][newy];
                }
                pq.push({heightMap[newx][newy] , {newx , newy}});
                visited[newx][newy] = 1;
            }
        }
        return water;
    }
};
