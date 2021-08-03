TreeNode *buildTreeHelper(int inorder[], int start, int end,
                unordered_map<int, int> mp) {
		
	if(start > end) return NULL;
 
    // find the root node index in sequence `inorder[]` to determine the left and right subtree boundary
    int index = start;
    for(int j = start + 1; j <= end; j++)
    {
        // find node with minimum index in level order traversal that would be the root node of the sequence `inorder[start, end]`
        if (mp[inorder[j]] < mp[inorder[index]]) {
            index = j;
        }
    }
 
    // create root node
    TreeNode *root = new TreeNode(inorder[index]);
 
    root->left = buildTreeHelper(inorder, start, index - 1, mp);
    root->right = buildTreeHelper(inorder, index + 1, end, mp);
 
    return root;
}
 
// Construct a binary tree from inorder and level order traversals
TreeNode* buildTree(int in[], int level[], int n)
{
    // create a map to efficiently find the index of an element in a
    // level order sequence
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[level[i]] = i;
    }
 
    // construct the tree and return it
    return buildTreeHelper(in, 0, n - 1, mp);
}
