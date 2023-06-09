bool dfs(int node, int vis[], int path[], vector<int> adj[]){
  vis[node] = 1;
  path[node] = 1;
  for(auto it: adj[node]){
    if(!vis[it]){
      if(dfs(it, vis,path, adj)==true) return true;
    }
    else if(path[it])return true;
  }
  path[node] = 0;
  return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  int vis[n+1] = {0};
  int path[n+1] = {0};
  vector<int> adj[n+1];

  for(auto it: edges){
    adj[it.first].push_back(it.second);
  }

  for(int i=1;i<=n;i++){
    if(!vis[i]){
      if(dfs(i, vis, path, adj)==true) return true;
    }
  }
  return false;

}