#include <bits/stdc++.h> 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>> adj(n+1);
    for(auto it:g){
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }

    priority_queue<pair<int,pair<int,int>>> pq;
    vector<int> vis(n+1);
    pq.push({0,{1,-1}});
    vector<pair<pair<int, int>, int>> ans;

    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        int weight = abs(it.first);
        int node = abs(it.second.first);
        int par = abs(it.second.second);
        
        if(vis[node]) continue;
        vis[node] = 1;
        if(par!=-1)
        ans.push_back({{par, node}, weight});
        for(auto adjnode: adj[node]){
            int neigh = adjnode.first;
            int wt = adjnode.second;
            if(!vis[neigh]) pq.push(-wt, -neigh, -node);

        }

    }
    return ans;




}
