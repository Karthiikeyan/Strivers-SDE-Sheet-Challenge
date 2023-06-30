#include <bits/stdc++.h> 

bool is_possible(long long barrier, vector<int> &time, int m, int n){
	long long days = 1;
	long long timing = 0;
	for(long long i=0;i<m;i++){
		if(time[i]>barrier) return false;
		if(timing + time[i] > barrier){
			days += 1;
			timing = time[i];
		}
		else{
			timing += time[i];
		}
	}
	if(days > n){
		return false;
	}
	return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long left = 0;
	long long right = 0;
	long long ans = 0;
	for(long long i=0;i<m;i++){
		right += time[i];
	}

	while(left<=right){
		long long mid = (left+right)/2;
		if(is_possible(mid, time, m ,n)){
			ans = mid;
			right = mid-1;
		}
		else
		left = mid+1;
	}
	return ans;
}