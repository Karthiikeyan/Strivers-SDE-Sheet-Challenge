
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
   // Write your code here!
    // vector<int> ans;
    // if(root==NULL) return ans;
    // queue<BinaryTreeNode<int> *> q;
    // bool flag = true;
    // q.push(root);
    // while(!q.empty()){
    //     int n = q.size();
    //     vector<int> res(n,0);
    //     for(int i=0;i<n;i++){
    //         BinaryTreeNode<int> *node = q.front();
    //         q.pop();

    //         // int index = (flag) ? i : (n-i-1);
    //             if(flag)
    //                 res[i] = node->data;
    //             else
    //                 res[n - i - 1] = node->data;
    //         // res[index] = node->data;
    //         if(!node->left) q.push(node->left);
    //         if(!node->right) q.push(node->right);

    //     }
    //     for(auto it:res){
    //         ans.push_back(it);
    //     }
    //     flag = !flag;
    // }
    // return ans;
    
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool LtoR = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            
            int index = (LtoR) ? i : (n-i-1);
            temp[index] = node->data;
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        
        for(auto it : temp){
            ans.push_back(it);
        }
        LtoR = !LtoR;
    }

}