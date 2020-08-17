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
    vector<int> result;
    
    void helper(Node* root) {
        if(!root) return;
        
        result.push_back(root->val);
        for(auto &n : root->children) {
            helper(n);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        if(!root) return vector<int>();
        helper(root);
        return result;
    }
};
