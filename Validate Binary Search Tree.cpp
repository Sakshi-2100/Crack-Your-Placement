/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

class Solution {
public:
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        inorder(root);
        for(int i=0; i<ans.size()-1;i++){
            if(ans[i+1]<=ans[i])
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool helper(TreeNode* root, long min_val, long max_val){
        if(!root)
            return true;
        if(root->val <= min_val || root->val>=max_val)
            return false;
        return helper(root->left,min_val,root->val) && helper(root->right,root->val,max_val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN, LONG_MAX);
    }
};