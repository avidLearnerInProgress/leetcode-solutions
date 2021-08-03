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
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int i, int j, int &preorderIndex) {
        if(i > j or preorderIndex > preorder.size()) return NULL;
        
        int preorderValue = preorder[preorderIndex]; //get the preorder value to create the new node
        TreeNode *root = new TreeNode(preorderValue); //create new node
        
        int inorderIndex = inorderMap[preorderValue]; //get the index for dividing the inorder array into two parts
        preorderIndex++; //increment the preorderIndex for next recursive call
        
        root->left = buildTreeHelper(preorder, inorder, i, inorderIndex - 1, preorderIndex); //recurse for left and right subtrees
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, j, preorderIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0 or inorder.size() == 0) {
            return NULL;
        }
        int idx = 0;
        for(auto ele : inorder) {
            inorderMap[ele] = idx++;
        }
        
        int i = 0, j = preorder.size() - 1;
        int preorderIndex = 0;
        
        return buildTreeHelper(preorder, inorder, i, j, preorderIndex);
    }
};
