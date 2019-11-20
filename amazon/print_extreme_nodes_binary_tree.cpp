{
/* C++ program to print nodes of extreme corners
of each level in alternate order */
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
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
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
   printExtremeNodes(root);
   cout<<endl;
  }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root)
{
    // Your code here
    if(!root) return;
    
    queue<Node *> q;
    q.push(root);
    bool leftToRight = false;
    while(!q.empty()){
        int q_size = q.size();
        int nc = q_size;
        while(nc--){
            Node *top = q.front();
            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
            q.pop();
            
            if(leftToRight && nc == q_size -1)
                cout<<top->data<<" ";
            if(!leftToRight && nc == 0)
                cout<<top->data<<" ";
        }
        leftToRight = !leftToRight;
    }
}
