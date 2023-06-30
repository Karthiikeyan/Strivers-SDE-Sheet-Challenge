bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    while(root!=NULL && root->data!=x){
        root = (x<root->data) ? root->left : root->right;
    }
    return root!=NULL;
}