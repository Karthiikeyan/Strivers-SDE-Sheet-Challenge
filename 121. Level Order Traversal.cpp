vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            ans.push_back(node->val);
        }
    }
    return ans;
}