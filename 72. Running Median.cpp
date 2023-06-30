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

vector<int> findMid(int *arr, int n){
	
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

void findMedian(int *arr, int n)
{
    // Write your code here
    vector<int> temp;
    temp = findMid(arr, n);
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}

void findMedian(int *arr, int  n){
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;

    for(int i=0;i<n;i++){
        if(maxh.empty() || maxh.top()>=arr[i]) maxh.push(arr[i]);
        else minh.push(arr[i]);

        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }

        if(minh.size()<maxh.size()) cout<<maxh.top()<<" ";
        else cout<<(minh.top()+maxh.top())/2<<" ";
    }

}