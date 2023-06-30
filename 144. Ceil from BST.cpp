int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ceil = -1;
    while(root){
        if(root->data==x){
            ceil = root->data;
            return ceil;
        }
        else if(root->data >= x){
            ceil = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
        
    }
    return ceil;
}