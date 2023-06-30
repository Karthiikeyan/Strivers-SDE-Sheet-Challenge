void getInOrderTraversal(TreeNode *root, vector<int> &ans){
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