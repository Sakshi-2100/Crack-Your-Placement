Node* findPre(Node* root, int key){
    Node* prec = NULL;
    while(root!=NULL){
        if(root->key<key){
            prec=root;
            root=root->right;
        }
        else
            root=root->left;
    }
    return prec;
}
Node* findSucc(Node* root, int key){
    Node* succ = NULL;
    while(root!=NULL){
    if(root->key>key){
        succ = root;
        root=root->left;
    }
    else
        root=root->right;
    }
    return succ;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
pre = findPre(root,key);
suc = findSucc(root,key);

}