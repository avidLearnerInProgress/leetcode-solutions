void dSumUtil(Node *root, int d, map<int, int> &mp){
    if(!root) return;
    mp[d] += root->data;
    dSumUtil(root->left, d + 1, mp);
    dSumUtil(root->right, d, mp);
}
void diagonalSum(Node* root)
{
    // Add your code here
    if(!root) return;
    map<int, int> mp;
    dSumUtil(root, 0, mp);
    
    for(auto it = mp.begin(); it != mp.end(); it++)
        cout<<it->second<<" ";
    cout<<"\n";
}