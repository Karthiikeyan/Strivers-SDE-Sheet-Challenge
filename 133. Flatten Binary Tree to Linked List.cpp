void rec(TreeNode<int> *node, TreeNode<int> *&prev){
    if(!node) return;

    rec(node->right, prev);
    rec(node->left, prev);

    node->right = prev;
    node->left = NULL;
    prev = node;

}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return NULL;
    TreeNode<int> *prev = NULL;
    rec(root, prev);
    return prev;
}