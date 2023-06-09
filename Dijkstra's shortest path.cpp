#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int v, int edges, int src) {
    // Write your code here.
    vector<int> dist(v, INT_MAX);
    
    priority_queue<pair<int,int>> pq;

    pq.push({0, src});
    dist[src] = 0;
    vector<pair<int,int>> adj[v];
    for(auto it: vec){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int neigh = it.first;
            int wt = it.second;
            if(dist[neigh] > dist[node]+wt){
                dist[neigh] =  dist[node]+wt;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
    return dist;

}
