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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top() -> val < node -> val) {
                node -> left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top() -> right = node;
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};