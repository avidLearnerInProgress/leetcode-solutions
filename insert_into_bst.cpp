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

    //recursive
    TreeNode* insertIntoBST(TreeNode* root, int val) {
            
        if(!root) return new TreeNode(val);
        
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    
    
    //iterative
    TreeNode* insertIntoBST(TreeNode* root, int val) {
            
        if(!root) return new TreeNode(val);
        
        TreeNode *current = root;
        
        while(current) {
            
            if(val < current->val) {
                if(current->left) 
                    current = current->left;
                else {
                    current->left = new TreeNode(val);
                    break;
                }
            }
            else {
                if(current->right) 
                    current = current->right;
                else {
                    current->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
