class Solution {
    
    bool checkIsBipartite(vector<vector<int>> &graph, vector<int> &color, int &src) {
        
        queue<int> Q;
        color[src] = 1;
        Q.push(src);
        
        while(!Q.empty()) {
            auto node = Q.front();
            Q.pop();

            for(auto &neighbor : graph[node]) {
                if(color[neighbor] == -1) { //uncolored
                    color[neighbor] = 1 - color[node];
                    Q.push(neighbor);
                }
                else if(color[neighbor] == color[node]) { //colored but isSameAsParent?
                    return false;
                }
            }
        }    
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(!checkIsBipartite(graph, color, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
