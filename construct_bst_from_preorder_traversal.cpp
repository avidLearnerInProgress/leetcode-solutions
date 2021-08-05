#include<bits/stdc+.h>
using namespace std;

Node *helper(vector<int> &preorder, int &preorderIndex, int &min, int &max, int &key) {
    if(preorderIndex > preorder.size()) return NULL;
    Node *root = NULL;
    if(key > min and key < max) {
        root = new Node(key);
        preorderIndex += 1;
        
        if(preorderIndex < preorder.size()) {
            root->left = helper(preorder, preorderIndex, min, key, pre[preorderIndex]);
            root->right = helper(preorder, preorderIndex, key, max, pre[preorderIndex]);
        }
        
    }
    return root;
}


Node *constructBinaryTreeFromPreOrderTraversal(vector<int> &preorder) {
    
    if(preorder.size() == 0) return NULL;
    
    // Node *root = new Node(preorder[0]);
    int preorderIndex = 0;
    return helper(preorder, preorderIndex, INT_MIN, INT_MAX, preorder[0]);
    
    
}
