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
    bool helper(TreeNode *left, TreeNode *right){ 
        if(!left && !right) return true;
        if(!left || !right) return false;
        
        
        if(left->val == right->val){
            bool outPair = helper(left->left, right->right);
            bool inPair = helper(left->right, right->left);
            return outPair && inPair;
        }
        else{
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return helper(root->left, root->right);
    }
};

/*
def isSymmetric(self, root: TreeNode) -> bool:
        
        if not root:
            return True
    
        stack = [(root.left, root.right)]
        
        while stack:
            c = stack.pop()
            l, r = c[0], c[1]
            
            if not l and not r:
                continue
            if (l and not r) or (r and not l) or (l.val != r.val):
                return False
            stack.append((l.right, r.left))
            stack.append((l.left, r.right))
        return True
        
*/