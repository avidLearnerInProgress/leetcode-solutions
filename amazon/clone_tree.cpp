//https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1
{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node *random;
};
Node *cloneTree(Node *);
int printInorder(Node* a,Node *b)
{
    if ((a==NULL and b==NULL) or (a->random==NULL and b->random==NULL))
        return 1;
    if(a->random->data == b->random->data and printInorder(a->left,b->left) and printInorder(a->right,b->right))
        return 1;
    return false;
}
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->random=NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
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
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }
     }
     Node *t = cloneTree(root);
      if(t==root)
        cout<<0<<endl;
     else
     cout<<printInorder(root,t);
     cout<<endl;
  }
  return 0;
}
Node* cloneTree(Node* tree);

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/
/* The function should clone the passed tree and return 
   root of the cloned tree */
 
void helper(Node* t, Node* n){
    if(t == NULL) return;
    if(t->left != NULL){
        n->left = new Node();
        n->left->data = t->left->data;
    }
    n->random = t->random;
    if(t->right != NULL){
        n->right = new Node();
        n->right->data = t->right->data;
    }
    helper(t->left, n->left);
    helper(t->right, n->right);
}
   
   
Node* cloneTree(Node* tree)
{
   //Your code here
   Node* cloned = new Node();
   cloned->data = tree->data;
   helper(tree, cloned);
   return cloned;
}
