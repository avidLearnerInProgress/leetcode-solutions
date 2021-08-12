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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        int max_ = INT_MIN;
        int maxLevel = 0, level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int sum_ = 0;
            level++;
            while(n--) {
                auto current = q.front();
                q.pop();
                sum_ += current->val;
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            if(sum_ > max_){
                max_ = sum_;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};
