// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            
//         vector<vector<int>> graph(numCourses);
//         vector<int> indegree(numCourses,0);
        
//         for(auto edge : prerequisites)
//         {
//             graph[edge[1]].push_back(edge[0]);
//             indegree[edge[0]]++;
//         }
        
//         queue<int> Q;
        
//         for(int i = 0;i < numCourses;i++)
//             if(indegree[i] == 0)
//                 Q.push(i);
        
//         int counter = 0;
//         while(!Q.empty())
//         {
//             int u = Q.front();
//             Q.pop();
            
//             counter++;
//             for(auto v : graph[u])
//             {
//                 if(--indegree[v] == 0)
//                     Q.push(v);
//             }
//         }
//         return counter == numCourses;
//     }
// };

class Solution {
public:
    bool isCyclic(vector<int> pre[], vector<int> &visited, int node) {
        
        if(visited[node] == 1) return true; //in-process already..
        
        if(visited[node] == 0) { //processing unprocessed node..
            visited[node] = 1;
            for(auto child : pre[node]) {
                if(isCyclic(pre, visited, child))
                    return true;
            }
        }        
        visited[node] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> prereq[numCourses];
        for(auto edge : prerequisites) {
            prereq[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(isCyclic(prereq, visited, i)) {
                return false;
            }
        }
        return true;
    }
}; 
