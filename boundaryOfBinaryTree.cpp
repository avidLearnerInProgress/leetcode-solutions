class Solution {
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    void addLeaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        if (!isLeaf(root)) res.push_back(root->val);
        
		// add left boundary
        TreeNode* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) 
				res.push_back(curr->val);
            if(curr->left) 
				curr = curr->left;
            else curr = curr->right;
        }
        
		// add leaf nodes
        addLeaves(root, res);
		
		// add right boundary
        curr = root->right;
        vector<int> tmp; //to store the right boundary from bottom to top
        while(curr) {
            if(!isLeaf(curr)) tmp.push_back(curr->val);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
		
        for (int i=tmp.size()-1; i>=0; --i) 
            res.push_back(tmp[i]);
   
        return res;
    }
};
