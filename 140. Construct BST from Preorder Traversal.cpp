TreeNode<int>* rec(vector<int> &preOrder, int &i, int bound){
    if(preOrder.size()<=i || bound<=preOrder[i]) return NULL;
    TreeNode<int>* root = new TreeNode<int>(preOrder[i++]);
    root->left = rec(preOrder, i, root->data);
    root->right = rec(preOrder, i, bound);
    return root;
}



TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    return rec(preOrder, i, INT_MAX);
}