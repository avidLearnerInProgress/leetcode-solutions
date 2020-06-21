{
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void insert(Node *root, int a1,int a2, char lr){
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
		insert(root->left, a1, a2, lr);
		insert(root->right, a1, a2, lr);
	}
}
Node *convertToDLL(Node *root,Node **head_ref);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
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
		
		Node *head=NULL;
		root=convertToDLL(root,&head);
		
		while(head->right!=NULL){
			cout<<head->data<<" ";
			head=head->right;
		}
		
		cout<<head->data<<endl;
		while(head!=NULL){
			cout<<head->data<<" ";
			head = head->left;
		}
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
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
*/
Node *convertToDLL(Node *root,Node **head_ref)
{
//add code here.

    static Node* prev = NULL;
    if(!root) return NULL;
    convertToDLL(root->left, head_ref);
    
    if(!root->left && !root->right){ // if its a leaf node
        if(!(*head_ref))
            *head_ref = root;
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
    }
    convertToDLL(root->right, head_ref);
}