unordered_map<graphNode*, graphNode*> mp;
graphNode* dfs(graphNode* curr){
	if(mp.find(curr)!=mp.end()){
		return mp[curr];
	}
	
	graphNode* clone = new graphNode(curr->data);
	mp[curr] = clone;
	for(auto neigh: curr->neighbours){
		clone->neighbours.push_back(dfs(neigh));
	}
	return clone;
}


graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node==NULL) return NULL;
	graphNode* clone = node;
	if(clone->neighbours.size()==0)
	return clone;
	return dfs(node);
}