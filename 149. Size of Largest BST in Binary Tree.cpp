class Nodeval {
    public:
        int minval, maxval, maxSize;

        Nodeval(int min, int max, int size){
            minval = min;
            maxval = max;
            maxSize = size;
        }
};

Nodeval findSize(TreeNode<int>* node){
    if(node==NULL)
        return Nodeval(INT_MAX, INT_MIN, 0);
    
    auto left = findSize(node->left);
    auto right = findSize(node->right);

    if(left.maxval < node->data and node->data < right.minval){
        return Nodeval(min(left.minval, node->data), max(right.maxval, node->data),
            left.maxSize+right.maxSize+1);
    }
    return Nodeval(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));

}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return findSize(root).maxSize;
}
