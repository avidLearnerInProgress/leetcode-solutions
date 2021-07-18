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
    bool isCompleteTree(TreeNode* root) {
        if(!root) {
            return true;
        }
        // ok so what i have to do(hopefully) is a level order traversal
        
        queue<TreeNode *> qu;
        TreeNode *current = root;
        qu.push(current);
        
        bool isBoth = true; //checks is a node has both children or not
        
        while(!qu.empty()) {
            
            current = qu.front();
            qu.pop();
            
            
            if(current->left) {
                
                if(!isBoth) return false;
                qu.push(current->left);
                
            }
            else isBoth = false;
            
            
            if(current->right) {
                
                if(!isBoth) return false;
                qu.push(current->right);
                
            }
            else isBoth = false;
        }
        return true;
    }
};
