{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
int maxLevelSum(Node * root);
/* Function to get diameter of a binary tree */
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << maxLevelSum(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */


int maxLevelSum(Node * root)
{
    //Your code here
    if(!root) return 0;
    
    queue<Node* > q;
    q.push(root);
    
    int max_sum = root->data, curr_sum = 0;
    while(!q.empty()){
        curr_sum = 0;
        int nodeCount = q.size();
        while(nodeCount > 0){
           
            Node *currNode = q.front();
            q.pop();
            curr_sum += currNode->data;
            
            if (currNode->left != NULL) 
                q.push(currNode->left); 
        
            if (currNode->right != NULL) 
                q.push(currNode->right);     
            nodeCount--;
        }
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}