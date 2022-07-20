class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* insert(Node* root, int val){
        Node* temp = newNode(val);
        if(root==NULL)
            return temp;
        else if(root->left==NULL && root->data>val)
            root->left=temp;
        else if(root->right==NULL && root->data<val)
            root->right=temp;
        else if(root->data>val)
            return insert(root->left,val);
        else if(root->data<val)
            return insert(root->right,val);
    }
    Node* post_order(int pre[], int size)
    {
        //code here
        Node* root = newNode(pre[0]);
        for(int i=1;i<size;i++)
            insert(root,pre[i]);
        return root;
    }
};