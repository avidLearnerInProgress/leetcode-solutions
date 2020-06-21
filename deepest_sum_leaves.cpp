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
    int maxHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
    int sum = 0;
    
    int _dLS(TreeNode* root, int height, int level){
        if(!root) return 0;
        if(root->left==NULL and root->right==NULL and level == height){
            sum += root->val;
        }
        _dLS(root->left, height, level + 1);
        _dLS(root->right, height, level + 1);
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        int height = maxHeight(root);
        int level = 1;
        return _dLS(root, height, level);
    }
};