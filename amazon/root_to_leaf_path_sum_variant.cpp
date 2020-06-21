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
/* Function to get diameter of a binary tree */
long long treePathsSum(Node *root);
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
     cout << treePathsSum(root) << endl;
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

long long recursiveSum(Node *root, long long currentSum, long long &total){
    if(!root->left && !root->right){
        total += currentSum*10 + root->data;
        return total;
    }
    if(root->left){
        recursiveSum(root->left, currentSum*10 + root->data, total);
    }
    if(root->right){
        recursiveSum(root->right, currentSum*10 + root->data, total);
    }
}

long long treePathsSum(Node *root)
{
    //Your code here
    if(!root) return 0;
    long long total = 0, currentSum = 0;
    return recursiveSum(root, currentSum, total);
}