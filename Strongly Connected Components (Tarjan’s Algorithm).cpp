#include<bits/stdc++.h>
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfsT(int node, vector<int> &vis, vector<int> adjT[], vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it: adjT[node]){
        if(!vis[it]){
            dfsT(it, vis, adjT, temp);
        }
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    vector<int> vis(n,0);
    stack<int> st;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    vector<int> adjT[n];
    for(auto it: edges){
        adjT[it[1]].push_back(it[0]);
    }
    vis.assign(n,0);
    vector<vector<int>> ans;

    while(!st.empty()){
        int i = st.top();
        st.pop();
        
        if(!vis[i]){
            vector<int> temp;
            dfsT(i, vis, adjT, temp);
            ans.push_back(temp);
        }            
        

    }
    return ans;



}