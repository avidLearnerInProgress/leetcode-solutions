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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        //map of horizontal distance and list of Nodes coming within that positive distance
        map<int, vector<int> > m;
        int hd = 0; // horizontal distance
        vector<vector<int>> result;
        
        //queue for level order traversal
        queue<pair<TreeNode*, int>> q;
        q.push({root, hd});
        
        while(!q.empty()){
            set<pair<int, int>> sameposnodes;
            int sz = q.size();
            while(sz-- > 0) {
                
                auto [curr, hd] = q.front(); q.pop();
                sameposnodes.insert({hd, curr->val});
                
                if(curr->left)
                    q.push({curr->left, hd - 1});
                if(curr->right)
                    q.push({curr->right, hd + 1});
            }
            
            for(auto s : sameposnodes) m[s.first].push_back(s.second);
        }
        
        
        for(auto kv : m)  result.push_back(kv.second);
        return result;    
    }
};
