void res(int level, TreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->data);
    res(level+1, root->left,ans);
    res(level+1, root->right,ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    res(0,root, ans);
    return ans;  
}