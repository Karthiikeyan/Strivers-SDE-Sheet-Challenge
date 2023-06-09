bool dfs(int node,int par, vector<int>adj[], vector<int> &vis){
    if(vis[node]) return false;
    vis[node] = 1;
    for(auto neigh: adj[node]){
        if(!vis[neigh]){
            if(dfs(neigh, node, adj, vis))
                return true;
        }
        else if(neigh!=par) return true;
    }
    return  false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis))
            return "Yes";
            
        }
    }
    return "No";

    
}