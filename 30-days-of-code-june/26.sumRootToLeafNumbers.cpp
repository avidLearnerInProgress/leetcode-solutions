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
    void util(TreeNode *root, int &csum, int &gsum){
        if(!root) return;      
        csum = csum * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
            gsum += csum;
        util(root->left, csum, gsum);
        util(root->right, csum, gsum);
        csum /= 10; //once we reach one of the bottom of tree, then we start going up from root->left to root to root->right;
    }
    
    int util_try(TreeNode *root, int val){
        if(!root) return 0;
        val = val * 10 + root->val;
        if(!root->left && !root->right)
            return val;
        return util_try(root->left, val) + util_try(root->right, val);
    }
    
    int util_try_iter(TreeNode *root){
        if(!root) return 0;

        queue<TreeNode*> nodeQ;
        queue<int> sumQ;
        nodeQ.push(root);
        sumQ.push(root->val);
        int gsum = 0;
        
        while(!nodeQ.empty()){
            TreeNode *curr = nodeQ.front();
            nodeQ.pop();
            
            int csum = sumQ.front();
            sumQ.pop();
            
            if(!curr->left && !curr->right) //basecase
                gsum += csum;
            
            if(curr->left){
                nodeQ.push(curr->left); //ok..
                sumQ.push((csum * 10) + curr->left->val); //not so ok..
            }
            
            if(curr->left){
                nodeQ.push(curr->right); //ok..
                sumQ.push((csum * 10) + curr->right->val); //not so ok..
            }
        }
        return gsum;
    }
    
    int sumNumbers(TreeNode* root) {
       if(root == NULL) return 0;
       int csum = 0, gsum = 0;
       return util_try(root,csum);
    }
};
