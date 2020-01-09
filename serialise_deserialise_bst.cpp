/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }
        istringstream in(data);
        queue<int> q;
        string val;
        while(in >> val) {
            q.push(stoi(val));
        }
        return deserializeHelper(q, INT_MIN, INT_MAX);
    }
private:
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if(root == NULL)
            return;
        out << root -> val << " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }
    TreeNode* deserializeHelper(queue<int>& q, int lower, int upper) {
        if(q.empty())
            return NULL;
        int cur = q.front();
        if(cur < lower || cur > upper) {
            return NULL;
        }
        TreeNode* root = new TreeNode(cur);
        q.pop();
        root -> left = deserializeHelper(q, lower, cur);
        root -> right = deserializeHelper(q, cur, upper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));