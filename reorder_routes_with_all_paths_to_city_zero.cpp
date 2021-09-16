class Solution {  
    int dfs(vector<vector<int>> &adjList, vector<bool> &visited, int source) {
        int reorderRoutesCount = 0;
        visited[source] = true;
        for(auto dest : adjList[source]) {
            if(!visited[abs(dest)]) {                
                reorderRoutesCount += dfs(adjList, visited, abs(dest)) + (dest > 0);
            }
        }
        return reorderRoutesCount;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //based on votrubac's solution
        
        vector<vector<int> > adjList(n);
        vector<bool> visited(n, false);
        
        for(auto &c : connections) {
            adjList[c[0]].push_back(c[1]); //from parent to child ==> +ve distance
            adjList[c[1]].push_back(-c[0]); //from child to parent ==> -ve distance
        }
        //find all the positive distance nodes via dfs and add them to the reorderRoutesCount.
        return dfs(adjList, visited, 0);
    }
    
    
    //we don't need the entire visited array, just keeping the track of parent is enough I believe.
     int minReorder(int n, vector<vector<int>>& connections) {
        //based on votrubac's solution
        
        vector<vector<pair<int, int> > > adjList(n);
        
        for(auto &c : connections) {
            adjList[c[0]].emplace_back(c[1], 1); //from parent to child ==> +ve distance
            adjList[c[1]].emplace_back(c[0], 0); //from child to parent ==> -ve distance
        }
         
        //find all the positive distance nodes via dfs and add them to the reorderRoutesCount.
         int reorderRoutesCount = 0;
         function <void(int, int)> dfs = [&](int source, int parent = -1) {
             for(auto &[dest, edge] : adjList[source]) {
                 if(dest == parent) {
                     continue;
                 }
                 reorderRoutesCount += edge;
                 dfs(dest, source);
             }
         };
        dfs(0, -1);
        return reorderRoutesCount;
    }
};
