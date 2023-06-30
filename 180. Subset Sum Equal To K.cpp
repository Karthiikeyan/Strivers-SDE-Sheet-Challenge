#include <bits/stdc++.h> 

bool res(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return true;
    if(ind==0) return arr[0]==k;
    if(dp[ind][k]!=-1) return dp[ind][k];
    int notTake = res(ind-1, k, arr, dp);
    int take = false;
    if(arr[ind]<=k){
        take = res(ind-1, k-arr[ind], arr, dp);
    }
    return dp[ind][k] = take | notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));
    
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            
            bool notTake = dp[ind-1][tar];
            bool take = false;
            if(arr[ind]<=tar){
                take = dp[ind-1][tar-arr[ind]];
            }
            dp[ind][tar] = take | notTake;
        }
    }
    return dp[n-1][k];

}