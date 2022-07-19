class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k)
                return true;
            else if(ans[i]+ans[j]>k)
                j--;
            else
                i++;
        }
        return false;
    }
};

class BSTIterator{
    bool reverse = true;
    stack<TreeNode*> st;
  public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(!reverse)
                node=node->left;
            else
                node=node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        BSTIterator f(root,false);
        BSTIterator l(root,true);
        int i = f.next();
        int j = l.next();
        while(i<j){
            if(i+j==k)
                return true;
            else if(i+j>k)
                j=l.next();
            else
                i=f.next();
        }
        return false;
    }
};