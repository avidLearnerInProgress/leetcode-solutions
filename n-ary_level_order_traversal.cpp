/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) 
            return vector<vector<int>>(); // return {} -> also works;
        
        vector<vector<int>> alevel;
        vector<int> clevel;
        
        queue<Node*> q; 
        q.push(root); 
        
        while (!q.empty()) {
            int sz = q.size(); 
            while(sz--){
                Node* c = q.front(); 
                q.pop(); 
                clevel.push_back(c->val); 
                for (auto node : c->children) 
                     q.push(node);
            }
            alevel.push_back(clevel);
            clevel.clear();
        }
        return alevel;
    }
};