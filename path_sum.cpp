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
    
    //recursive TC: O(n) / SC: O(1)    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        //basecases
        if(!root) return false;
        if(!root->left and !root->right and targetSum == root->val) return true;
        
        //hypothesis
        targetSum -= root->val;
        
        //induction
        return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }
    
    //iterative TC: O(n) / SC: O(n)    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        int sum = 0;
        queue<TreeNode *> qu;
        
        TreeNode *current = root;    
        qu.push(current);
        
        while(!qu.empty()) {
            
            current = qu.front();
            qu.pop();
            
            if(!current->left and !current->right) {
                if(current->val == targetSum)
                    return true;
            } 
            
            if(current->left) {
                current->left->val += current->val;
                qu.push(current->left);
            }
            if(current->right) {
                current->right->val += current->val;
                qu.push(current->right);
            }
            
        }
        return false;
    }
};
