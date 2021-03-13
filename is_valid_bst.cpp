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
    //as per my understanding
    //the minNode and maxNode during traversal must point to the parent of the current node that we are exploring
    bool isValidBSTHelper(TreeNode *root, TreeNode *min, TreeNode *max) {
        if(!root) return true;
        
        if(min and root->val <= min->val || max and root->val >= max->val) return false;
        
        return isValidBSTHelper(root->left, min, root) and isValidBSTHelper(root->right, root, max); 
    }
    
    bool isValidBST(TreeNode* root) {
       // if(!root) return true;
        return isValidBSTHelper(root, NULL, NULL);
    }
};
