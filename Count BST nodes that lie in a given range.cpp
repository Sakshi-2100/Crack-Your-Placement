/*
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
*/

class Solution{
public:
int count =0;
    void helper(Node* root, int l, int h){
        if(root==NULL)
        return;
        if(root->data>=l && root->data<=h)
        count++;
        helper(root->left,l,h);
        helper(root->right,l,h);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      helper(root,l,h);
      return count;
    }
};
