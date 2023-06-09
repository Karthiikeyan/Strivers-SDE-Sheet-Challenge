void getInOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    getInOrderTraversal(root->left, ans);
    getInOrderTraversal(root->right, ans);    
    ans.push_back(root->data);

}void getInOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    getInOrderTraversal(root->left, ans);
    getInOrderTraversal(root->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    getInOrderTraversal(root, ans);
    return ans;
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    getInOrderTraversal(root, ans);
    return ans;
}