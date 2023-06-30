bool getpath(TreeNode<int> *node, vector<int> &ans, int x){
	if(!node) return false;
	ans.push_back(node->data);
	if(node->data == x) return true;
	
	if(getpath(node->left, ans, x) || getpath(node->right, ans, x)) return true;

	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	if(!root) return ans;
	getpath(root, ans, x);
	return ans;

}
