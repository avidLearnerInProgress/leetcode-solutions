class Solution {
public:
    int flag = 0;
    void isCycle(int node, vector<int> &visited, vector<int> pre[], vector<int> &result) {
        
        if(visited[node] != 0) {
            return;
        }
        
        visited[node] = 1;
        for(auto child : pre[node]) {
            if(visited[child] == 0)
                isCycle(child, visited, pre, result);
            else if(visited[child] == 1) {
                flag = 1;
            }
        }
        visited[node] = 2;
        result.push_back(node);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> prereq[numCourses];
        vector<int> visited(numCourses, 0);
        vector<int> result;        
    
        for(auto edge : prerequisites) {
            prereq[edge[1]].push_back(edge[0]);
        }
        
        for(int i=0; i<numCourses; i++) {
            isCycle(i, visited, prereq, result);
        }    
        if(flag) {
            result.clear();
            return result;
        }
        else
            reverse(result.begin(), result.end());
        
        return result;

    }
};
