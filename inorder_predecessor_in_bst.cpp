/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        
    
        if(root == nullptr) {
            return nullptr;
        }
        
        if(root->val >= p->val) {
            return inorderPredecessor(root->left, p);
        }
        
        TreeNode *pre = inorderPredecessor(root->right, p);
        return pre == nullptr ? root : pre;
    
    }
};
