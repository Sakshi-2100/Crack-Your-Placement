class NodeValue{
    public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue checkLargestBST(TreeNode<int>* root){
    if(root==NULL)
        return NodeValue(INT_MAX,INT_MIN,0);
    auto left = checkLargestBST(root->left);
    auto right = checkLargestBST(root->right);
    if(left.maxNode<root->data && root->data<right.minNode)
        return NodeValue(min(root->data, left.minNode), max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return checkLargestBST(root).maxSize;
}
