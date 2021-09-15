class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //find all nodes in DAG with inDegree as 0
        
        vector<int> res, indegree(n);
        
        for(auto &edge: edges) {
            indegree[edge[1]]++;
        }
        
        for(int i=0; i!=n; ++i) {
            if(indegree[i]==0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
