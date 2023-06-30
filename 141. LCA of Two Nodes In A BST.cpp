TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL) return NULL;
    TreeNode<int>* cur = root;

    if(cur->data > P->data && cur->data > Q->data){
        return LCAinaBST(root->left, P,Q);
    }
    else if(cur->data < P->data && cur->data < Q->data){
        return  LCAinaBST(root->right, P,Q);
    }
    return root;

}
