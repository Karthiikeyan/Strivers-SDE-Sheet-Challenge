TreeNode<int> *constTree(vector<int> &inorder, int in1, int in2, vector<int> &preorder, int pre1, int pre2, map<int,int>&mpp){
    if(in1 > in2 || pre1 > pre2) return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[pre1]);

    int inRoot = mpp[preorder[pre1]];
    int numsleft = inRoot - in1;

    root->left = constTree(inorder, in1, inRoot-1, preorder, pre1+1, pre1+numsleft, mpp);
    root->right = constTree(inorder, inRoot+1, in2, preorder, pre1+numsleft+1, pre2, mpp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n = inorder.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[inorder[i]] = i;
    }

    return constTree(inorder, 0, n-1, preorder, 0, n-1, mpp);
}