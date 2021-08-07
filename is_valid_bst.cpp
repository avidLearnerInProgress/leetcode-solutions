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
    //using range min and max
    bool helper(TreeNode *root, long min, long max) {
        if(!root) return true;
        
        if(root->val <= min or root->val >= max) {
            return false;
        }
        
        return helper(root->left, min, root->val) and helper(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root, LONG_MIN, LONG_MAX);
        
    }
    
    //using prev node recursive
    TreeNode *prev;
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        
        if(!isValidBST(root->left))
            return false;
        
        //the prev node here keeps track of the prev node to the current node.
        //we are doing inorder traversal (LVR). Always, the last-seen node must be smaller than the current node.
        if(prev != NULL and prev->val >= root->val)
            return false;
        prev = root;
        
        if(!isValidBST(root->right))
            return false;  
        
        return true;
    }
    
    //iterative
    bool isValidBST(TreeNode *root) {
        
        TreeNode *current = root, *prev = NULL;
        stack<TreeNode *> st;
        
        while(!st.empty() or current) {
            
            if(current) {
                st.push(current);
                current = current->left;
            }
            else {
                auto parent = st.top();
                st.pop();
                
                if(prev and parent->val <= prev->val) return false;
                prev = parent;
                current = parent->right;
            }
        }
        return true;
    }
    
};
