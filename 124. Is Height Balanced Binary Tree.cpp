int balanced(BinaryTreeNode<int>* node){
    if(!node) return 0;

    int left = balanced(node->left);
    if(left==-1) return -1; 
    int right = balanced(node->right);
    if(right == -1) return -1;

    if(abs(left-right)>1) return -1;
    return max(left, right)+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return balanced(root)!=-1;
}