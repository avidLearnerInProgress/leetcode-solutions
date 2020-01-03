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
    int getModeCount(TreeNode* root, unordered_map<int, int> &umap){
        if(root == NULL) return 0;
        umap[root->val]++;
        return max(umap[root->val], max(getModeCount(root->left, umap), getModeCount(root->right, umap))); 

        //max of max..
        //get mode count from map..
        //find the pair in map with mc = modecount and then append all the node->data with same mc to the result vector
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> umap; //unordered because we dont need order :p
        vector<int> result;
        
        int modeCount = getModeCount(root, umap);
        for(auto it : umap){
            if(it.second == modeCount)
                result.push_back(it.first);
        }
        return result;
    }
};