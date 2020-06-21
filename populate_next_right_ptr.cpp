/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        
        if(root->left){ //check if child exists
            if(root->right) //check if immediate right node of child exists, if yes change the next ptr
                root->left->next = root->right;
            if(root->next) //check if neighbour of root exists for subtree, if yes, change the left subtree next ptr to right subtree
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};