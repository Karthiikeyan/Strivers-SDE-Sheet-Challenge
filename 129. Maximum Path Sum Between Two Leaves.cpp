long long int maxSum(TreeNode<int> *root, long long int &maxi){
    if(!root) return 0;

    long long int left = max((long long int)0, maxSum(root->left, maxi));
    long long int right = max((long long int)0, maxSum(root->right, maxi));

    maxi = max(maxi, left + right + root->val);
    return max(left,right)+root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int maxi = 0;
    if(!root || !root->right || !root->left) return -1;
    maxSum(root, maxi);
    return maxi;
}