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
    //recursive
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (!root) return 0;
        
        int ans = 0; //ans holds result of current node at hand.
        if (low <= root->val && root->val <= high) { //current node within the boundaries [low, high]
            ans += root->val;
        }
        
        //current node is not in boundaries [low, high]
        //it means the range [low, high] can occupy children of current node, so we recurse
        
        //disect the [low <= node.val <= high] condition into two parts...
        //if current node is not in range and if current node is <= high - recurse for right half
        if (root->val <= high) {
            ans += rangeSumBST(root->right, low, high);
        }
        
        //if current node is not in range and if low <= current node - recurse for left half
        if (low <= root->val) {
            ans += rangeSumBST(root->left, low, high);
        }
        
        return ans;
    }
    
    //iterative
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (!root) return 0;
        int sum = 0;
        stack<TreeNode *> st;
        st.push(root);
        
        
        while(!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            
            if(!current) 
                continue;
            
            if(low <= current->val and current->val <= high) {
                sum += current->val;
            }
            
            if(low <= current->val) {
                st.push(current->left);
            }
            
            if(current->val <= high) {
                st.push(current->right);
            }
            
        }
        return sum;
    }
};
