// { Driver Code Starts
#include<bits/stdc++.h>
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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
class Solution{
  public:
    // Function should return all the ancestor of the target node
    //recursive
    // bool helper(Node *root, int target, vector<int> &result) {
        
    //     if(!root) return false;
        
    //     if(root->data == target) return true;
        
    //     bool left = helper(root->left, target, result);
    //     bool right = helper(root->right, target, result);
        
    //     if(left or right) {
    //         result.push_back(root->data);
    //         return true;
    //     }
    //     return false;
    // }
    
    // vector<int> Ancestors(struct Node *root, int target)
    // {
    //      // Code here
    //      vector<int> result;
    //      if(!root) return result;
         
    //      helper(root, target, result);
    //      return result;
    // }
    
    
    //iterative
    
    void setParent(Node *root, unordered_map<int, int> &parent) {
        
        if(!root) return;
        
        stack<Node *> st;
        st.push(root);
        
        while(!st.empty()) {
            auto current = st.top();
            st.pop();
            
            if(current->right) {
                parent[current->right->data] = current->data;
                st.push(current->right);
            }
            
            if(current->left) {
                parent[current->left->data] = current->data;
                st.push(current->left);
            }
        }
    }
    
    vector<int> Ancestors(struct Node *root, int target)
    {
        // Code here
        if(!root) return {};
        
        vector<int> result;
        unordered_map<int, int> parent;
        parent[root->data] = 0;
        
        setParent(root, parent);
        
        while(target = parent[target]) {
            result.push_back(target);
            cout<<target<<" ";
        }
        return result;
    }
    
    
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin, s);
        
        int target;
        cin>>target;
        getchar();
        
        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root,target);
        for(int i = 0;i<nodes.size();i++){
            cout<<nodes[i]<<" ";
        }
        cout<< endl;
    }
    return 1;
}
  // } Driver Code Ends
