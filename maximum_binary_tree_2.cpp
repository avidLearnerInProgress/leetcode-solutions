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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        TreeNode *curr = root;
        TreeNode *node = new TreeNode(val);
        
        if(curr->val < val){
            node->left = curr;
            return node;
        }
        
        while(curr->right != NULL && curr->right->val > val){
            curr = curr->right;
        }
        node->left = curr->right;
        curr->right = node;
        return root;
    }
};