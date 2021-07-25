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
// recursive
    void horizontalDistanceHelper(TreeNode *root, map<int, vector<pair<int, int>>> &mp, int height, int hd) {
        if(!root) return;
        
        mp[hd].push_back({height, root->val});
        
        horizontalDistanceHelper(root->left, mp, height + 1, hd - 1);
        horizontalDistanceHelper(root->right, mp, height + 1, hd + 1);
    }    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        
        map<int, vector<pair<int, int>> > mp;
        vector<vector<int>> result;
        horizontalDistanceHelper(root, mp, 0, 0);
        int i = 0;
        
        for(auto [k,v] : mp) {
            vector<int> hdResult;
            
            sort(v.begin(), v.end(), [](auto a, auto b) {
                if(a.first == b.first) return a.second < b.second;
                else return a.first < b.first;
            });
                 
            for(auto &[a, b]: v) {
                hdResult.push_back(b);
            }
            result.push_back(hdResult);
            hdResult.clear();
        }
        return result;  
    }
    
// iterative
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        
        map<int, vector<int>> mp; //map of horizontal distance and list of Nodes coming within that positive distance
        queue<pair<TreeNode*, int>> qu; //queue to keep track of level. => pair<node, horizontal_distance>
        
        qu.push({root, 0});
        
        while(!qu.empty()) {
            int n = qu.size();
            multiset<pair<int, int>> samelevelnodes;
            
            while(n-- > 0) {
                auto [current, hd] = qu.front(); 
                samelevelnodes.insert({hd, current->val});
                qu.pop();
            
                if(current->left) 
                    qu.push({current->left, hd - 1});
                
                if(current->right) 
                    qu.push({current->right, hd + 1});
            }
            for(auto s : samelevelnodes) {
                mp[s.first].push_back(s.second);
            }
        }
        
        for(auto kv : mp) {
            result.push_back(kv.second); //here kv.second is a vector of nodes at the hd(kv.first)
        }
        return result;  
    }
};
