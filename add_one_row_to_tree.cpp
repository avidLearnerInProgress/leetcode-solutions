/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void addOneRowRecursive(TreeNode* root, int v, int depth, int current_depth) {
        if(!root) return;
        
        if(current_depth == depth) { //breaking condition
            TreeNode *subLeft = root->left; //store the current left
            root->left = new TreeNode(v); //add new nodes with value = v at current_depth
            root->left->left = subLeft; //attach previous left to left of new root->left
            
           TreeNode *subRight = root->right;
            root->right = new TreeNode(v);
            root->right->right = subRight;
            return;
        }
        addOneRowRecursive(root->left, v, depth, current_depth + 1);
        addOneRowRecursive(root->right, v, depth, current_depth + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) { //depth == 1, detach current root, add new root and add the older tree to the left of new root
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        addOneRowRecursive(root, v, d, 2);
        return root;
    }
};
