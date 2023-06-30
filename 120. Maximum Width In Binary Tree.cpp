int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int maxi = 0;
    if(!root) return maxi;
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        maxi = max(maxi, n);
        for(int i=0;i<n;i++){
            TreeNode<int> *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return maxi;

}