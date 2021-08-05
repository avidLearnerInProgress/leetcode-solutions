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
    void flatten(TreeNode* root) {
        /*
        
                1                  1                1
                /\                / \               \
               2  5     =>       2   5      =>.      2
              / \  \             \   \                \
             3   4  6             3   6                3
                                   \                    \
                                    4                    4
                                                          \
                                                           5
                                                            \
                                                             6
            In the above problem, we have to traverse in preorder fashion and change left subtree to right subtree. Once we do that, we have to fix the right subtree below the changed left subtree.
        */
        
        
        
        if(!root or (!root->left and !root->right)) return; //important to traverse back from leaf node to the parent node.
        
        if(root->left) { //check first if we have a left subtree from current root
            
            flatten(root->left); //recurse until the leftmost child in current tree
            
            TreeNode *tempRight = root->right; //store the right child of original tree into a temporary variable
            
            root->right = root->left; //stick left half to right half(check node 3, 4 in diagram)
            root->left = NULL; //set the left of original tree to NULL
            
            TreeNode *current = root->right; //stick right half of original tree(tempRight) below new right subtree
            while(current->right != NULL) {
                current = current->right;
            }
            
            current->right = tempRight;
        }
    
        flatten(root->right);
    }
};
