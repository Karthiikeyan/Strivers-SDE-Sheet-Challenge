TreeNode<int>* constTree(vector<int> &inOrder, int in1, int in2, vector<int> &postOrder, int post1, int post2, map<int,int> &mpp){
     if(in1 > in2 || post1 > post2) return nullptr;

     TreeNode<int>* root = new TreeNode<int>(postOrder[post2]);

     int inRoot = mpp[postOrder[post2]];
     int numsleft = inRoot - in1;

     root->left = constTree(inOrder, in1, inRoot-1, postOrder, post1, post1+numsleft-1, mpp);
     root->right = constTree(inOrder, inRoot+1, in2, postOrder, post1+numsleft, post2-1, mpp);

     return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n = inOrder.size();
     map<int,int> mpp;
     for(int i=0;i<n;i++){
          mpp[inOrder[i]] = i;
     }
      
     return constTree(inOrder, 0, n-1, postOrder, 0, n-1, mpp);

}