/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

// O(n)        O(h)
class Solution {
public:
    void helper(TreeNode* root, int level, vector<int> &res){
        if(root==NULL)
            return;
        if(res.size()==level)
            res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
};