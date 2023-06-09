void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root) return;
    int child = 0;
    if(root->left)
    child += root->left->data;
    if(root->right)
    child += root->right->data;

    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->left or root->right) root->data = sum;
}  