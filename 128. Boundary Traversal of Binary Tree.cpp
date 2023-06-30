bool isLeaf(TreeNode<int>* root){
    if(!root->left && !root->right) return true;
    return false;
}

void leftboundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* node = root->left;
    while(node){
        if(!isLeaf(node)) ans.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void rightboundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* node = root->right;
    vector<int> temp;
    while(node){
        if(!isLeaf(node)) temp.push_back(node->data);
        if(node->right) node = node->right;
        else node = node->left;
    }
    for(int i=temp.size()-1; i>=0;--i){
        ans.push_back(temp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}



vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftboundary(root, ans);
    addLeaves(root, ans);
    rightboundary(root, ans);
    return ans;
}