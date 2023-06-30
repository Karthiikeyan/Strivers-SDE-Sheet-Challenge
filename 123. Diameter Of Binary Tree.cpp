int height(TreeNode<int> *root, int &diameter){
    if(!root) return 0;

    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    diameter = max(diameter,(left+right));
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int diameter = 0;
    height(root, diameter);
    return diameter;
}