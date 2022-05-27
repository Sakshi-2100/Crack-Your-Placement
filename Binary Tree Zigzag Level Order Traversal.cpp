/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (size-i-1);
                level[index] = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};