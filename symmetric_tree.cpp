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
    bool helper(TreeNode *left, TreeNode *right){ 
        if(!left && !right) return true;
        if(!left || !right) return false;
        
        
        if(left->val == right->val){
            bool outPair = helper(left->left, right->right);
            bool inPair = helper(left->right, right->left);
            return outPair && inPair;
        }
        else{
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return helper(root->left, root->right);
    }
};