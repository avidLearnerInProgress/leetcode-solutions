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
    int widthOfBinaryTree(TreeNode* root) {
    
       if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            ans = max(ans,q.back().second-q.front().second+1);
            while(size--)
            {
                auto front = q.front();
                q.pop();
                if(front.first->left)
                    q.push({front.first->left,2LL*front.second});
                if(front.first->right)
                     q.push({front.first->right,2LL*front.second+1});
            }
        }
        return ans;
    }
};
