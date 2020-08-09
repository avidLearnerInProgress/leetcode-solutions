# class Solution:
#     def orangesRotting(self, grid: List[List[int]]) -> int:
#         from collections import deque    
#         n,m = len(grid), len(grid[0])
#         fresh = 0 #counts of 1's
#         rotten = deque([])

#         for i in range(n):
#             for j in range(m):
#                 if grid[i][j] == 2: rotten.append((i, j)) #all 2's
#                 if grid[i][j] == 1: fresh += 1
#         print(fresh)

#         dir_x = [1, -1, 0, 0]
#         dir_y = [0, 0, 1, -1]
#         minutes = 0

#         while rotten:
#             #operations = 0 #bool check
#             for _ in range(len(rotten)): 
#                 a, b = rotten.popleft()
#                 for x,y in zip(dir_x, dir_y):
#                     X = a + x
#                     Y = b + y
#                     if 0 <= X < n and 0 <= Y < m and (grid[X][Y] == 1):
#                         #print("Subtracting fresh..")
#                         grid[X][Y] = 2
#                         fresh -= 1
#                         rotten.append((X, Y))
#             minutes += 1
#         return max(0, minutes-1) if fresh == 0 else -1

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
        
//         //get rows and cols
//         auto r = grid.size(), c = grid[0].size();
        
//         auto fresh_count = 0; //count of fresh oranges
//         queue<pair<int, int>> rotten_indices; //indices of rotten oranges for BFS
        
//         for(auto i=0; i<r; i++) {
//             for(auto j=0; j<c; j++) {
//                 if(grid[i][j] == 1) fresh_count++;
//                 if(grid[i][j] == 2) rotten_indices.push({i, j});
//             }
//         }
        
//         cout<<fresh_count<<"\n";
        
//         int minutes = -1; //minimum number of minutes
//         vector<pair<int, int>> direction = {{1,0}, {0,1}, {-1,0}, {0, -1}}; //top bottom left right
        
//         while(!rotten_indices.empty()) {
//             for(auto itr=0; itr<rotten_indices.size(); itr++) {
//                 auto [cx, cy] = rotten_indices.front();
//                 rotten_indices.pop();
//                 for(auto [dx, dy] : direction) {
//                     int cdx = cx + dx, cdy = cy + dy;
                    
//                     if(cdx < 0 || cdy < 0 || cdx >= r || cdy >= c || grid[cdx][cdy] == 2 || grid[cdx][cdy] == 0) continue;
                    
//                     else{ //its a fresh orange
//                         grid[cdx][cdy] = 2; //rotten it.
//                         fresh_count-=1; //decrement fresh count
//                         rotten_indices.push({cdx, cdy}); //add rotten index to queue
//                     }
//                 }       
//             }
//             minutes+=1;                                
//         }
//         if(fresh_count > 0) return -1; // one or more oranges are not reachable
//         if(minutes == -1) return 0; //since its initialized as -1 and if after computation we are at -1; there are no oranges
//         return minutes;
//     }
// };


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};
