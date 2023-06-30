void inorder(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    if(k>n) return -1;
    return ans[n-k];

}