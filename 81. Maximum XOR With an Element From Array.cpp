// Solution 1

#include<bits/stdc++.h>

struct Node {
	Node* linked[2];
	
	bool containsKey(int bit){
		return (linked[bit]!=NULL);
	}
	Node* get(int bit){
		return linked[bit];
	}
	void put(int bit, Node* node){
		linked[bit] = node;
	}

};

class Trie {
	private:
	Node* root;

	public:

	Trie() {
		root = new Node();
	}
	void insert(int num){
		Node* node = root;
		for(int i=31;i>=0;i--){
			int bit = (num>>i) & 1;
			if(!node->containsKey(bit)){
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}

	int findMax(int num){
		Node* node = root;
		int maxi = 0;
		for(int i=31;i>=0;i--){
			int bit = (num>>i)&1;
			if(node->containsKey(!bit)){
				maxi = maxi | (1<<i);
				node = node->get(!bit);
			}else{
				node = node->get(bit);
			}
		}
		return maxi;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie trie;
	sort(arr.begin(), arr.end());
	int ai;
	int xi;
	int i=0;
	vector<pair<int, pair<int,int>>> offline_q;
	for(auto it:queries){
		ai = it[1];
		xi = it[0];
		offline_q.push_back({ai, {xi, i++}});
	}

	int q = offline_q.size();
	int n = arr.size();
	i = 0;

	sort(offline_q.begin(), offline_q.end());
	vector<int> ans(q,0);

	for(auto &it : offline_q) {
		ai = it.first;
		xi = it.second.first;
		int qInd = it.second.second;
        while(i < n && arr[i] <= ai) {
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[qInd] = trie.findMax(xi); 
        else ans[qInd] = -1; 
    }
	return ans;
}

// Solution 2

#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    int n=arr.size();
    sort(arr.begin(), arr.end());
    vector<int>res;
	for(int i=0;i<queries.size();i++){
        int idx=lower_bound(arr.begin(), arr.end(), queries[i][1])-arr.begin();
        int idxx=0;
        if(arr[idx]==queries[i][1]) idxx=idx;
        else if(arr[idx]>queries[i][1]) idxx=idx-1;
        else if(idx>=n) idxx=n-1;
        int ans=-1;
        for(int j=0;j<=idxx;j++){
            ans=max(ans, arr[j]^queries[i][0]);
        }
        res.push_back(ans);
    }
    return res;
}