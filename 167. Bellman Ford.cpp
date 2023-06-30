#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    for(int i=0;i<n-1;i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u]!=1e9 && dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dist[u]!= 1e9 && dist[v]>dist[u]+w){
            return -1;
        }
    }
    return dist[dest];
}