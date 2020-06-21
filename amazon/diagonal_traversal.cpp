multimap <int,int> m;
void inorder(Node * root,int hd) {
    if(!root) return;
    
    m.insert({hd, root->data});
    inorder(root->left, hd+1);
    inorder(root->right, hd);
    
}

void diagonalPrint(Node *root) {

    inorder(root,0);
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
    m.clear();

}

/*void diagonalPrint(Node *root)
{
   // your code here
    queue<Node *> q;
    q.push(root);
     while(!q.empty()){
        Node *t=q.front();
        while(t){
            cout<<t->data<<" ";
            if(t->left)
                q.push(t->left);
            t=t->right;
        }
        q.pop();
    }
}*/