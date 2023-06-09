bool dfs(int node, int col, int color[], vector<int> adj[]){
	color[node] = col;
	for(auto neigh: adj[node]){
		if(color[neigh]==-1){
			if(dfs(neigh, !col, color, adj)==false) return  false;
		}
		else if(color[neigh]==col) return false;
	}
	return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	vector<int> adj[n+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int color[n+1];
	for(int i=0;i<=n;i++) color[i]=-1;

	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(dfs(i,0, color, adj)== false) return false;
		}
	}
	return true;
}