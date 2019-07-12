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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isRightToLeft = true;
        vector<vector<int>> res;
        while(!dq.empty()){
            isRightToLeft = !isRightToLeft;
            int sze = dq.size();
            vector<int> lans;
            while(sze--){
                if(isRightToLeft == false){ //left to right     
                    //push_back pop_front
                    TreeNode *top = dq.back();
                    dq.pop_back();
                    lans.push_back(top->val);                   
                    if(top->left)
                        dq.push_front(top->left);
                    if(top->right)
                        dq.push_front(top->right);
                }
                else{
                    TreeNode *top = dq.front();
                    dq.pop_front();
                    lans.push_back(top->val);                   
                    if(top->right)
                        dq.push_back(top->right);
                    if(top->left)
                        dq.push_back(top->left);
                    
                }
            }
            res.push_back(lans);
        }
        return res;
    }
};
    