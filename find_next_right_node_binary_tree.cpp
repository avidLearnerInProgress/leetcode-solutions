/*----find next right node -----*/
Node *findNextRightNode(Node* root, int k){
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
                int sz = q.size();
                while(sz-- > 0){
                        Node *curr = q.front();
                        q.pop();
                        if(curr->data == k){
                                if(sz)
                                        printf("%d ", q.front()->data);
                                else
                                        printf(-1);
                                return;
                        }
                        if(curr->left)
                                q.push(curr->left);
                        if(curr->right)
                                q.push(curr->right);
                }
        }
}
