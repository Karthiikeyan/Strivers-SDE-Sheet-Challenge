#include<bits/stdc++.h>
int rec(int ind, int w, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp){
	if(ind==0){
		if(weights[0]<=w) return values[0];
		else return 0;
	}
	if(dp[ind][w]!=-1) return dp[ind][w]; 
	int notTake = 0 + rec(ind-1, w, values, weights, dp);
	int take = INT_MIN;
	if(weights[ind]<=w) take = values[ind] + rec(ind-1, w-weights[ind], values, weights, dp);
	return dp[ind][w] = max(notTake, take);
}



int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int> (w+1,-1));
	return rec(n-1, w, values, weights, dp);
	for(int ind=0;ind<n;ind++) dp[0][w] = values[0];

	for(int ind=1;ind<n;ind++){
		for(int wt=0;wt<n;wt++){
			if(dp[ind][w]!=-1) return dp[ind][w]; 
			int notTake = 0 + dp[ind-1][w];
			int take = INT_MIN;
			if(weights[ind]<=w) take = values[ind] + dp[ind-1][w-weights[ind]];
			dp[ind][w] = max(notTake, take);
		}
	}
	return dp[n-1][w];
	
}