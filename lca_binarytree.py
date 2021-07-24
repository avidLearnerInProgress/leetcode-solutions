# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    
    
    # recursive
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        if not root or root == p or root == q: # find p or q
            return root
        
        
        pExists = self.lowestCommonAncestor(root.left, p, q)
        qExists = self.lowestCommonAncestor(root.right, p, q)
        
        if pExists and qExists: # both p and q lie in different subtrees
            return root
            
        return pExists if pExists else qExists # either you are having p == q or p and q(which are different) lie in same subtree
    
    
    # Another idea : Collect paths of p and q from the root and save them in aux array. Now find a node that's not common and    return the node previous to the uncommon node(which by definition is common)

    #      bool tracePath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path){
    #         if(root == NULL)
    #             return false;
    #         if(root == p){
    #             path.push_back(p);
    #             return true;
    #         }

    #         path.push_back(root);
    #         if(tracePath(root->left, p, path)){
    #             return true;
    #         }
    #         else if(tracePath(root->right, p, path)){
    #            return true;
    #         }
    #         path.pop_back();
    #         return false;
    #     }  

    #     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    #         vector<TreeNode*> pathOfP,pathOfQ;

    #         tracePath(root, p, pathOfP);
    #         tracePath(root, q, pathOfQ);

    #         int i;
    #         for(i=0; i<pathOfP.size() && i<pathOfQ.size(); i++){
    #             if(pathOfP[i] != pathOfQ[i])
    #                 break;
    #         }
    #         return pathOfP[i-1];
    #     }

    
    
    
