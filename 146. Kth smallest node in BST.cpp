int kthSmallest(TreeNode<int> *root, int &k)
{
	//	Write the code here.
    if(root==NULL) return -1;

    int left = kthSmallest(root->left, k);
    if(left!=-1) return left;

    k--;
    if(k==0) return root->data;

    int right = kthSmallest(root->right, k);
    if(right!=-1) return right;

    return -1;
}