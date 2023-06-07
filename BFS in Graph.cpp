#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int>> adj(V);
    for(auto it: edges){
        adj[it.first].insert(it.second);
        adj[it.second].insert(it.first);
    }

    queue<int> q;
    vector<int> vis(V,0);
    vector<int> ans;
    
    for(int i=0;i<V;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();q.pop();
                if(vis[node])continue;
                vis[node] = 1;
                ans.push_back(node);
                for(auto it: adj[node]){
                    if(vis[it])continue;
                    if(!vis[it]){
                        q.push(it);
                    }
                }
            }
        }
    }
    return ans;

}