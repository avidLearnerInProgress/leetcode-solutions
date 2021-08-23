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
    void partialInorder(TreeNode *root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
public:
        
    /* TC: O(1) | SC: O(h) */
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    int next() {
        auto nextSmallest = st.top();
        st.pop();
        
        if(nextSmallest->right) {
            partialInorder(nextSmallest->right);
        }
        return nextSmallest->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
