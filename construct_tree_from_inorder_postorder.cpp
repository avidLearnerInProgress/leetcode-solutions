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
    unordered_map<int, int> inorderMap;
    TreeNode *buildTreeHelper(vector<int> &postorder, int i, int j, int &postorderIndex) {
        if(i > j) return NULL;
        
        int postorderValue = postorder[postorderIndex]; //get the postorder value to create the new node
        TreeNode *root = new TreeNode(postorderValue); //create new node
        
        int inorderIndex = inorderMap[postorderValue]; //get the index for dividing the inorder array into two parts
        postorderIndex--; //decrement the preorderIndex for next recursive call
        
        //recurse for right subtree first and then the left subtree(since its a postorder traversal)
        root->right = buildTreeHelper(postorder, inorderIndex + 1, j, postorderIndex);
        root->left = buildTreeHelper(postorder, i, inorderIndex - 1, postorderIndex); 
        
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size() == 0 or inorder.size() == 0) {
            return NULL;
        }
        
        int idx = 0;
        for(auto ele : inorder) {
            inorderMap[ele] = idx++;
        }
        
        int i = 0, j = postorder.size() - 1;
        int postorderIndex = postorder.size() - 1;
        
        return buildTreeHelper(postorder, i, j, postorderIndex);
    }
};
