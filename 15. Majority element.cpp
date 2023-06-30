#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	map<int,int> mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}

	int ans = n/2;
	for(auto it: mpp){
		if(it.second>ans)
		return it.first;
	}
	return -1;
}