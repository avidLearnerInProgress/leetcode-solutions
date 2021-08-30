// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    Node* mapParentsAndFindTarget(Node* root, int &target, unordered_map<Node*, Node*> &parentMap) {
        if(!root) {
            return NULL;
        }
        Node* targetNode = NULL;
        queue<Node* > Q;
        Q.push(root);
        
        while(!Q.empty()) {
            auto current = Q.front();
            Q.pop();
            if(current->data == target) {
                targetNode = current;
            }
            
            if(current->left) {
                parentMap[current->left] = current;
                Q.push(current->left);
            }
            
            if(current->right) {
                parentMap[current->right] = current;
                Q.push(current->right);
            }
        }
        
        return targetNode;    
    }
    
    int minTimeHelper(Node* root, unordered_map<Node*, Node*> &parentMap) {
        
        
        int timeToBurn = 0;
        unordered_map<Node*, bool> visited;
        
        queue<Node* > Q;
        Q.push(root);
        visited[root] = true;
        
        while(!Q.empty()) {
            bool isBurnPossible = false;
            int size = Q.size();
            while(size--) {
                auto current = Q.front();
                Q.pop();
                
                //left child in BFS
                if(current->left and !visited[current->left]) {
                    isBurnPossible = true;
                    visited[current->left] = true;
                    Q.push(current->left);
                }
                
                //right child in BFS
                if(current->right and !visited[current->right]) {
                    isBurnPossible = true;
                    visited[current->right] = true;
                    Q.push(current->right);
                }
                
                //parent in BFS
                if(parentMap[current] and !visited[parentMap[current]]) {
                    isBurnPossible = true;
                    visited[parentMap[current]] = true;
                    Q.push(parentMap[current]);
                }
            }
            if(isBurnPossible) {
                timeToBurn++;
            }
        }
        return timeToBurn;
    }
    
  public:
    int minTime(Node* root, int target) {
        // Your code goes here
        
        //create parent pointers and find the exact location of target node.
        unordered_map<Node*, Node*> parentMap;
        
        Node* targetNode = mapParentsAndFindTarget(root, target, parentMap);
        if(!targetNode) {
            return 0; //the target node is not present in tree, 0 seconds taken to burn the tree from target node
        }
        
        return minTimeHelper(targetNode, parentMap);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
