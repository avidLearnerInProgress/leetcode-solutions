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
    TreeNode *xparent, *yparent;
    int xdepth, ydepth;
            
    void helper(TreeNode *root, TreeNode *parent, int x, int y, int depth) {
        
        if(!root) return;
        
        if(root->val == x) {
            xdepth = depth;
            xparent = parent;
            return;
        }
        
        else if(root->val == y) {
            ydepth = depth;
            yparent = parent;
            return;
        }
        
        else {
            helper(root->left, root, x, y, depth + 1);
            helper(root->right, root, x, y, depth + 1);
        }
    }
    
    // recursive
    bool isCousins(TreeNode *root, int x, int y) {
       if(!root) return false;
        helper(root, NULL, x, y, 0);
        
        if((xdepth == ydepth) and (xparent != yparent)) return true;
        else return false;
    }

    // iterative
    bool isCousins(TreeNode *root, int x, int y) {

        queue<TreeNode* > qu;
        bool xFound = false, yFound = false;
        int xParent = 0, yParent = 0;
        qu.push(root);

        while(!qu.empty() and !xFound and !yFound) {
            int n = qu.size();
            while(n-- > 0) {
                auto current = qu.front();
                qu.pop();

                if(current->left) {
                    qu.push(current->left);
                    if(current->left->val == x) {
                        xParent = current->val;
                        xFound = true;
                    }  
                    if(current->left->val == y) {
                        yParent = current->val;
                        yFound = true;
                    }  
                }

                if(current->right) {
                    qu.push(current->right);
                    if(current->right->val == x) {
                        xParent = current->val;
                        xFound = true;
                    }  
                    if(current->right->val == y) {
                        yParent = current->val;
                        yFound = true;
                    }  
                } 
            }
        }
        return xFound and yFound and xParent != yParent;
    }
};
