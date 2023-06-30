vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> mpp;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root,{0,0}});
    
    while(!q.empty()){

        TreeNode<int>* node = q.front().first;
        int vertical = q.front().second.first;
        int level = q.front().second.second;
        q.pop();

        mpp[vertical][level].push_back(node->data);
        if(node->left!=NULL)
        q.push({node->left,{vertical-1, level+1}});
        if(node->right!=NULL)
        q.push({node->right,{vertical+1, level+1}});
    }

    for(auto val: mpp){
        for(auto it: val.second){
            for(auto i: it.second){
                ans.push_back(i);
            }
        }
    }
    return ans;
}