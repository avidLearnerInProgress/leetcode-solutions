class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(numCourses,vector<bool>(numCourses, false));
        for(auto it : prerequisites) {
            adj[it[0]][it[1]] = true;
        }       
        
        for(int k = 0; k < numCourses; k++) {
            for(int i = 0; i < numCourses; i++) {
                for(int j = 0; j < numCourses; j++) {
                    if(!adj[i][j] && adj[i][k] && adj[k][j]) {
                        adj[i][j]=true;
                    }
                }
            }
        }
        
        vector<bool> result;
        for(auto it: queries) {
            result.push_back(adj[it[0]][it[1]]);
        }
        return result;
    }
};
