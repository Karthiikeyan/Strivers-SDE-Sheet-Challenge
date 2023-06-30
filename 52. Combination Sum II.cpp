#include<bits/stdc++.h>

void combinations(int ind, int target, int n, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
	
	if(target==0){
		ans.push_back(ds);
		return;
	}

	for(int i=ind;i<n;i++){
		if(i>ind and arr[i]==arr[i-1]) continue;
		if(arr[i]>target) break;
		ds.push_back(arr[i]);
		combinations(i+1, target-arr[i], n, arr, ds, ans);
		ds.pop_back();
	}

		
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> ds;
	combinations(0, target, n, arr, ds, ans);
	return ans;
}
