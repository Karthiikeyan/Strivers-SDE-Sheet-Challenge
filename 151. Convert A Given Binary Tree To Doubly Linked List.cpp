// void solve(BinaryTreeNode<int>* &root, BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head){
//     if(root == NULL)
//         return;
     
//     solve(root->left, prev, head);
//     if(prev==NULL){
//         head = root;
//     }
//     else{
//         root->left = prev;
//         prev->right = root;
//     }
//     prev = root;
//     solve(root->right, prev, head);
// }

// BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
//     // Write your code here
//     BinaryTreeNode<int>* prev = NULL;
//     BinaryTreeNode<int>* head = NULL;
//     solve(root, prev, head);
//     return head;
// }

void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &pre,                                       BinaryTreeNode<int>* &head){
    if(root == NULL)
        return ;
    
    solve(root->left, pre, head);
    if(pre == NULL)
        head = root;
    else{
        pre->right = root;
        root->left = head;
    }
        pre = root;

    solve(root->right, pre, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* pre = NULL;
    BinaryTreeNode<int>* head = NULL;
    solve(root, pre, head);
    return head;
}