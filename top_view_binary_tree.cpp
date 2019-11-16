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
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void topView(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
     struct Node *root = NULL;
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
     topView(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    
    map<int, int> m;   //node->data, vertical_dist
    queue<pair<Node*, int>> q; //node, verticaL_dist
    q.push({root, 0});
    while(!q.empty()){
        pair<Node*, int> top = q.front();
        Node* c = top.first;
        int hd = top.second;
        q.pop();
        if(m.find(hd) == m.end()){
            //v.push_back(c->data);
            m[hd] = c->data; 
        }
        if(c->left)
            q.push({c->left, hd - 1});
        
        if(c->right)
            q.push({c->right, hd + 1});
    }
    for(auto i: m)
        cout<<i.second<<" ";   
}