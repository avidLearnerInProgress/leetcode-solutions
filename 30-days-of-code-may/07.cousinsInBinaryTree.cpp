/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int parent_x = -1, parent_y = -1, depth_x = -1, depth_y = -1, x, y;
    
    void findDepthAndCheckParent(TreeNode* root, int depth) {
        if(root == NULL) return;
        if(root->left && root->left->val == x || root->right && root->right->val == x) parent_x = root->val;
        
        if(root->left && root->left->val == y || root->right && root->right->val == y) parent_y = root->val;
        if(root->val == x) depth_x = depth;
        if(root->val == y) depth_y = depth;
        
        findDepthAndCheckParent(root->left, depth + 1);
        findDepthAndCheckParent(root->right, depth + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        this->x = x, this->y = y;
        findDepthAndCheckParent(root, 0);
        return (depth_x == depth_y) && (parent_x != parent_y);
           
    }
};