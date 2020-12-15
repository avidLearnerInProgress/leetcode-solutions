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
private:
    int height(TreeNode* root, int &diameter) {
        
        if(!root) return 0;
        
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        
        diameter = max(diameter, leftHeight + rightHeight + 1); //this is the smart trick to avoid computing recursive diameter again here...at any point in the recursion..diameter will be left + right + 1
        
        return 1 + max(leftHeight, rightHeight); //standard height recursive call..
    }
     
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        
        height(root, diameter);
        return diameter == INT_MIN ? 0 : diameter-1;
    }
};
