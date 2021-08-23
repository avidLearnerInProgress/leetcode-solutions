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

class BSTIterator {
        
    stack<TreeNode*> st;
    bool reverse;
    
    void partialInorder(TreeNode *root) {
        while(root) {
            st.push(root);
            root = !reverse ? root->left : root->right;
        }
    }
    public:    
        BSTIterator(TreeNode *root, bool reverse = false) : reverse(reverse) {
            partialInorder(root);
        }
        
        int next() {
            auto next = st.top();
            st.pop();
            
            auto itr = !reverse ? next->right : next->left; //for leftItr(check right subtree) and inverse for other 
            if(itr) {
                partialInorder(itr);
            }
            return next->val;
        }
};

/*based on approach mentioned here - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/1420711*/
/*TC: O(n) | SC: O(h)*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftItr(root), rightItr(root, true);
        int left = leftItr.next(), right = rightItr.next();
        
        while(left < right) {
            if(left + right == k) return true;
            if(left + right < k)
                left = leftItr.next();
            else
                right = rightItr.next();
        }
        return false;
    }
};
