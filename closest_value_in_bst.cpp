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
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    void helper(TreeNode *root, double target, int &closest) {
        if(!root) return;

        if(abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }

        if(root->val < target) {
            helper(root->right, target, closest);
        }
        else {
            helper(root->left, target, closest);
        }
        
    }

    int closestValue(TreeNode * root, double target) {
        // write your code here
        int closest = -1;
        helper(root, target, closest);
        return closest;
    }
};
