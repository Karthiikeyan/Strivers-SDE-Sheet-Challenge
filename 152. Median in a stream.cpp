#include<bits/stdc++.h>

void balanced_heap(priority_queue<int> &max, priority_queue<int, vector<int>, greater<int>> &min){
	if(max.size()>min.size()+1){
		int x = max.top();
		min.push(x);
		max.pop();
	}
	else if(min.size()>max.size()){
		int x = min.top();
		max.push(x);
		min.pop();
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here
	vector<int> ans; 
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;

	for(int i=0;i<n;i++){
		if(max.size()==0 || max.top()>arr[i])
			max.push(arr[i]);
		else
			min.push(arr[i]);

		balanced_heap(max, min);

		if(i%2==0)
			ans.push_back(max.top());
		else
			ans.push_back((min.top()+max.top())/2);
	}
	return ans;
}
