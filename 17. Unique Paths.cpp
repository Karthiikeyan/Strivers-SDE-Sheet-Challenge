#include <bits/stdc++.h> 

int countpaths(int i, int j, vector<vector<int>>&dp){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;

	if(dp[i][j]!=-1) return dp[i][j];
	else return dp[i][j] = countpaths(i-1, j, dp) + countpaths(i, j-1, dp);

}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n,-1));
	return countpaths(m-1, n-1, dp);

}