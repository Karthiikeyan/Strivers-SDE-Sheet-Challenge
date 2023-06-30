bool summertric(BinaryTreeNode<int>* lnode, BinaryTreeNode<int>* rnode){
    if(!lnode || !rnode) return lnode==rnode;
    
    if(lnode->data!= rnode->data) return false;
    
    return summertric(lnode->left, rnode->right) && summertric(lnode->right, rnode->left);
}
