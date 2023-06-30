vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,int> mpp;
    vector<int> ans;
    if(!root) return ans;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});

    while(!q.empty()){
        TreeNode<int> *node = q.front().first;
        int level = q.front().second;
        q.pop();
        if(mpp[level]==0){
            mpp[level] = node->val;
        }
        if(node->left!=NULL){
            q.push({node->left, level-1});
        } 
        if(node->right!=NULL){
            q.push({node->right,level+1});
        }
    }
    
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}