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
    
    string util(TreeNode *root, string s){
        if(!root) return "";
        s = string(1, 'a' + root->val) + s;
        if(!root->left && !root->right){
                return s;
        }
        
        if(root->left && root->right){
            return min(util(root->left, s), util(root->right, s));
        }
        
        else if(root->left)
            return util(root->left, s);
        else if(root->right)
            return util(root->right, s);
        else
            return "";
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        return util(root, s);
    }
};