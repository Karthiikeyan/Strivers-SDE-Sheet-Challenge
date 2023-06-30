bool isValid(BinaryTreeNode<int> *node,long long minVal, long long maxVal){
    if(node==NULL) return true;
    if(node->data>maxVal || node->data<minVal) return false;
    return isValid(node->left, minVal, node->data) && isValid(node->right, node->data, maxVal);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isValid(root, LONG_MIN, LONG_MAX);
}