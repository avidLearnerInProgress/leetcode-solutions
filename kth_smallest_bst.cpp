// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> result;
    
//     void traversal(TreeNode *root){
//         if(!root) return;
//         traversal(root->left);
//         result.push_back(root->val);
//         traversal(root->right);
//     }
    
    
//     int kthSmallest(TreeNode* root, int k) {
//         if(!root) return 0;
//         traversal(root);
        
//         int ans = *(result.begin() + k - 1);
//         cout<<ans;
//         return ans;
//     }
// };



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
    void helper(TreeNode *root, int k, int &count, int &ans) {
        if(!root) return;
        
        if(root->left) {
            helper(root->left, k, count, ans);
        }
        
        count++;
        if(count == k) {
            ans = root->val;
            return;
        }
        
        if(root->right) {
            helper(root->right, k, count, ans);
        }
        
    }
    
public:
    
    //recursive
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) {
            return -1;
        }
        
        int count = 0, ans = -1;
        helper(root, k, count, ans);
        return ans;
    }
    
    //iterative
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) {
            return -1;
        }
        
        stack<TreeNode *> st;
        
        while(root or !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();

                if(--k == 0) {
                    return root->val;
                }
                root = root->right;
            }
        }
        
        return -1;
    }
};
