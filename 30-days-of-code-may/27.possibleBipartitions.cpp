class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> color;
    
    bool bfs(int u){
        //if(color[u] == -1) return false;
        color[u] = 1;
        
        queue<int> qu;
        qu.push(u);
        
        while(!qu.empty()){
            auto i = qu.front();
            qu.pop();
            for(auto j : graph[i]){ //for all neighbors of node i in the graph
                if(color[j] == -1){
                    color[j] = 1 - color[i];
                    qu.push(j);
                }
                else if(color[j] == color[i]) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        if(N == 0) return false;
        
        for(auto &d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        
        color.resize(N+1, -1); //unassigned color
        for(int i=1; i<=N; i++){
            if(color[i] == -1){
                if(!bfs(i)) return false;
            }
        }
        return true;
    }
};
