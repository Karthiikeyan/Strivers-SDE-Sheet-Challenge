void getInOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    getInOrderTraversal(root->left, ans);
    getInOrderTraversal(root->right, ans);    
    ans.push_back(root->data);

}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    getInOrderTraversal(root, ans);
    return ans;
}