// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


class Solution
{
    public:
    
    void horizontalDistanceHelper(Node *root, map<int, int> &mp, int hd) {
        if(!root) return;
        
        if(mp.find(hd) == mp.end()) {
            mp[hd] = root->data;
        }
        
        if(root->left)
            horizontalDistanceHelper(root->left, mp, hd - 1);
        
        if(root->right)
            horizontalDistanceHelper(root->right, mp, hd + 1);
    }    
    
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    
    // recursive -- doesnt work correctly for some reason
    vector<int> topView(Node *root)
    {
        //Your code here
        if(!root) return {};
        
        map<int, int > mp;
        vector<int> result;
        horizontalDistanceHelper(root, mp, 0);
        for(auto it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
    
    
    // iterative
    vector<int> topView(Node *root)
    {
        if(!root) return {};
        
        vector<int> result;
        map<int, int> mp;   //node->data, hd
        queue<pair<Node*, int>> q; //node, hd
        q.push({root, 0});
        
        while(!q.empty()) {
            pair<Node*, int> top = q.front();
            Node* c = top.first;
            int hd = top.second;
            q.pop();
            
            if(mp.find(hd) == mp.end()){ // only when we encounter first time
                mp[hd] = c->data; 
            }
            
            if(c->left)
                q.push({c->left, hd - 1});
            
            if(c->right)
                q.push({c->right, hd + 1});
        }
        
        for(auto i: mp)
            result.push_back(i.second);
        return result;
    }
};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
