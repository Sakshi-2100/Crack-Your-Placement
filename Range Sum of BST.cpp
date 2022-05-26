/*

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

*/

class Solution {
public:
    int ans =0;
    void inorder(TreeNode* root, int low, int high){
        if(root==NULL)
            return ;
        inorder(root->left, low, high);
        if(root->val>= low && root->val<=high)
            ans+=root->val;
        inorder(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root,low,high);
        return ans;
    }
};


//Using prop of BST
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root==NULL){
            return 0;
        }
        if(root->val>=low && root->val<=high)
            sum+=root->val;
        if(root->val<high)
            sum+=rangeSumBST(root->right,low,high);
        if(root->val>low)
            sum+=rangeSumBST(root->left,low,high);
            
        return sum;
    }
};