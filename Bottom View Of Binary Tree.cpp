#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int,int> mpp;
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root,0});

    while(!q.empty()){
        BinaryTreeNode<int> *node = q.front().first;
        int level = q.front().second;
        q.pop();
        mpp[level] = node->data;
        if(node->left!=NULL){
            q.push({node->left, level-1});
        } 
        if(node->right!=NULL){
            q.push({node->right,level+1});
        }
    }
    vector<int> ans;
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
    
}
