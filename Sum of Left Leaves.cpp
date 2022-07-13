/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(root==NULL)
            return false;
        return !root->left && !root->right;
    }
    void helper(TreeNode* root, int &ans){
        if(root==NULL)
            return;
        if(isLeaf(root->left))
            ans+=root->left->val;
        helper(root->left,ans);
        helper(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};