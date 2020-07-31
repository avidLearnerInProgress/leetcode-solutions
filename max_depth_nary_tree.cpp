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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        queue<Node* > q;
        q.push(root);
        
        int depth = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) { //increment depth after visiting all nodes at current level in the queue
                auto current = q.front();
                q.pop();
                for(auto n : current->children) //for all children of current node
                    q.push(n);

            }
            depth++;
        }
        return depth;
    }
};
