class Solution {
public:
//     vector <vector<int>> res;
//     void solve(vector<vector<int> >& graph, int node, int target, vector<int>temp){
//       temp.push_back(node);
//       if(node == target){
//          res.push_back(temp);
//          return;
//       }
//       for(int i=0; i<graph[node].size(); i++){
//          solve(graph, graph[node][i], target, temp);
//       }
//     }

//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//       vector<int> temp;
//       solve(graph, 0, graph.size() - 1, temp);
//       return res;
//     }
    void recurse(vector<vector<int>>& graph, vector<int>& curr, vector<vector<int>>& result, int node) {
        if(node == graph.size() - 1) {
            curr.push_back(node);
            result.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(node);
        for(auto it : graph[node]) {
            recurse(graph, curr, result, it);
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        vector<vector<int>> result;

        recurse(graph, curr, result, 0);
        return result;
    }
};
