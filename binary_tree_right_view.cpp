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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        //find last node of each level in the level order traversal
        vector<int> rightMost;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            int c = 0;
            while (c++ < sz)
            {
                auto current = q.front();
                q.pop();
                if(c == sz)
                    rightMost.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return rightMost;
    }
};