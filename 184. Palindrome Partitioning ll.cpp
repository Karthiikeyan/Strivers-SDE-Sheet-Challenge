#include <bits/stdc++.h> 

bool is_palindrome(int low, int high, string &str){
    while(low<high){
        if(str[low]!=str[high]) return false;
        low++;
        high--;
    }
    return true;
}

int f(int i, int n, string &str, vector<int> &dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost_min = INT_MAX;
    for(int j=i;j<n;j++){
        if(is_palindrome(i,j,str)){
            int cost = 1+f(j+1, n, str, dp);
            cost_min = min(cost, cost_min);
        }
    }
    return dp[i] = cost_min;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) -1;
}
