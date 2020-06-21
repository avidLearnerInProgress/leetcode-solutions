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
    
    TreeNode* helper(TreeNode* root, int val){
        if(root == NULL) return root;
        
        if(root->val == val) return root;
        else if(root->val < val) return helper(root->right, val);
        else return helper(root->left,val);
        
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL) return root;
        return helper(root, val); 
    }
};