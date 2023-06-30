#include<bits/stdc++.h>
long res(int ind, int t, int *a, vector<vector<long long>> &dp){
    if(ind==0){
        return t%a[0]==0;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    long long notTake = res(ind-1, t, a, dp);
    long long take = 0;
    if(a[ind]<=t) take = res(ind, t - a[ind], a, dp);
    return dp[ind][t] = notTake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long long>> dp(n, vector<long long> (value+1, -1));
    return res(n-1, value, denominations, dp); 
}