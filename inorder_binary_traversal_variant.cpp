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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>(0);
        
        stack<TreeNode *> st;
        vector<int> result;
        
        TreeNode *current = root;
        
        while(current != NULL || !st.empty()){
            while(current != NULL){
                st.push(current);
                current = current->left;                
            }
            //current is empty but stack isnt
            current = st.top();
            st.pop();
            if(current->val >= INT_MIN && current->val <= INT_MAX)
                result.push_back(current->val);
            current = current->right;
        }
        
        /*for(auto &&x : result)
            cout<<x<<"\n";*/
        
        return result;
    }
};