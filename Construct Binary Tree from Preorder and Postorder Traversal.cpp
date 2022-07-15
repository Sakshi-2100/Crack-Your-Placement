/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int> &mp){
        if(preStart>preEnd || postStart>postEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd)
            return root;
        int postIndex = mp[preorder[preStart+1]];
        int len = postIndex-postStart+1;
        root->left = buildTree(preorder,preStart+1,preStart+len,postorder,postStart,postIndex,mp);
        root->right = buildTree(preorder,preStart+len+1,preEnd,postorder,postIndex+1,postEnd-1,mp);
        return root;
    }
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<postorder.size();i++)
            mp[postorder[i]]=i;
        return buildTree(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mp);
    }

};