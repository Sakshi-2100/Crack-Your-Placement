/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

*/

    void helper(TreeNode* root, vector<int>&ans){
        if(root==NULL)
            return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int mini = INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i+1]-ans[i]<mini)
                mini=ans[i+1]-ans[i];
        }
        return mini;
    }
};

class Solution {
public:
    void helper(TreeNode* root, int &mini, int &prev){
        if(root==NULL)
            return;
        helper(root->left,mini,prev);
        mini = min(mini,abs(prev-root->val));
        prev = root->val;
        helper(root->right,mini,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int prev = INT_MAX/2;
        helper(root,mini,prev);
        return mini;
    }
};