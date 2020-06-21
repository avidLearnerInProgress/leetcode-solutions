{
#include<bits/stdc++.h>
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
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int mn=0;
int aa[10000];
void printVertical(Node *root);
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(aa,0,sizeof(aa));
		int n;
		cin>>n;
		mn=0;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
			if(root==NULL){
				root=new Node(a1);
				switch(lr){
					case 'L':root->left=new Node(a2);
					break;
					case 'R':root->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		printVertical(root);
		cout<<endl;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

map<int, int> m;
void printVerticalUtil(Node *root, int hd){
    if(!root) return;
    m[hd] += root->data;
    printVerticalUtil(root->left, hd - 1);
    printVerticalUtil(root->right, hd + 1);
}

void printVertical(Node *root)
{
//add code here.
    if(!root) return;
    /*
    queue<pair<Node*, int>> q; //node and its horizontal distance
    map<int, int> m; //distance
    
    q.push({root, 0});
    
    while(!q.empty()){
        pair<Node*, int> p = q.front();
        Node* curr = p.first;
        int hd = p.second;
        m[hd] += curr->data;
        
        if(curr->left != NULL)
            q.push({curr->left, hd - 1});  
        if(curr->right != NULL)
            q.push({curr->right, hd + s1});
    }*/
    printVerticalUtil(root, 0);
    
    for(auto it = m.begin(); it != m.end(); it++)
        cout<<it->second<<" ";
    m.clear();
}