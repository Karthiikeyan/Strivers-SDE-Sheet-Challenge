#include<bits/stdc++.h>
int res(int ind, int cut, vector<int> &price, vector<vector<int>> &dp){
	if(ind==0) return cut*price[0];
	if(dp[ind][cut]!= -1) return dp[ind][cut];
	int notTake = 0 + res(ind-1, cut, price, dp);
	int take = INT_MIN;
	int lenrod = ind+1;
	if(lenrod<=cut){
		take = price[ind] + res(ind, cut-lenrod, price, dp);
	}
	return dp[ind][cut] = max(take, notTake);

}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
	return res(n-1, n, price, dp);
}
