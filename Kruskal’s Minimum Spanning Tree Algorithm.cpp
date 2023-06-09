#include <bits/stdc++.h> 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<pair<int,int>> adj[n+1];
	for(auto it: graph){
		adj[it[0]].push_back({it[1],it[2]});
		adj[it[1]].push_back({it[0],it[2]});
	}


	priority_queue<pair<int,pair<int,int>>> pq;
    vector<int> vis(n+1);
    pq.push({0,{1,-1}});
    vector<pair<pair<int, int>, int>> ans;
	int totW = 0;
    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        int weight = abs(it.first);
        int node = abs(it.second.first);
        int par = abs(it.second.second);
        
        if(vis[node]) continue;
        vis[node] = 1;
        totW += weight;
        for(auto adjnode: adj[node]){
            int neigh = adjnode.first;
            int wt = adjnode.second;
            if(!vis[neigh]) pq.push({-wt, {-neigh, -node}});

        }

    }
	return totW;
}