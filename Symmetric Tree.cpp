/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

*/

class Solution {
public:
    bool helper(TreeNode* leftSubTree , TreeNode* rightSubTree){
        if(leftSubTree==NULL || rightSubTree==NULL)
            return leftSubTree == rightSubTree;
        if(leftSubTree->val != rightSubTree->val)
            return false;
        return helper(leftSubTree->left, rightSubTree->right) && helper(leftSubTree->right, rightSubTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || helper(root->left,root->right);
    } 
};