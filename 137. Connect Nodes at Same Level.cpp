void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    BinaryTreeNode< int > *prev;

    while(!q.empty()){
        int n = q.size();
        prev = NULL;
        while(n){
            BinaryTreeNode< int > *node = q.front();
            q.pop();
            if(prev!=NULL){
                prev->next = node;
            }
            prev = node;
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
            n--;
        }
    }
}