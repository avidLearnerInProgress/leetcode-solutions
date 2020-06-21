{
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
int findDist(Node* ,int ,int );
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/

Node *findLCA(Node *node, int a, int b){
    
    if(!node) return NULL;
    
    if(node->data == a || node->data == b) return node; //base cases
    
    Node *left = findLCA(node->left, a, b);
    Node *right = findLCA(node->right, a, b);
    
    if(left && right) return node; // root is the lca for both the nodes
    
    return (!left?right:left);
}

int height(Node *node, int a){
    if(node == NULL)
		return 0;

	if(node->data == a)
		return 0;

    queue<Node*> q;
    q.push(node);
    q.push(NULL);
    int h = 0;
    
    while(!q.empty()){
        Node *top = q.front();
        q.pop();
        
        if(!top){
            if(!q.empty()){
                q.push(NULL);
            }
            h++;
        }
        else{
            if(top->data == a)
                return h;
                
            if(top->left)
                q.push(top->left);
                
            if(top->right)
                q.push(top->right);
        }
    }
    return h;
}

int findDist(Node* root, int a, int b)
{
    // Your code here 
    if(!root) return -1;
    Node *lca = findLCA(root, a, b);
    int p = height(lca, a);
    int q = height(lca, b);
    return p + q;
    
}