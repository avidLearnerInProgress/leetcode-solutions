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
    
    
    int helper(TreeNode *root, int low, int high) {
        if(!root) return 0;
        
        int sum = 0;
        
        if(root->val >= low and root->val <= high) {
            sum += root->val;
        }
        if(root->val >= low) { //it means that the high(upperlimit) is less than root->val and the high will lie within the left half of subtree
            sum += helper(root->left, low, high);
        }
        
        if(root->val <= high) { //it means that the low is higher than root-val and low will lie within the right half of subtree
            sum += helper(root->right, low, high);
        }
        
        return sum; //propagate sum to the root node
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(!root) return 0;
        return helper(root, low, high);
    }
};
