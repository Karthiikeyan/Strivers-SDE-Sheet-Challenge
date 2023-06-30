void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &comp){
    if(vis[node]) return;
    vis[node] = 1;
    comp.push_back(node);
    for(auto neigh: adj[node]){
        if(!vis[neigh]){
            dfs(neigh, vis, adj, comp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for(int i=0;i<V;i++){
        if(!vis[i]){
        vector<int> comp;
        dfs(i, vis, adj, comp);
        ans.push_back(comp);
        }
        
    }
    return ans;
}