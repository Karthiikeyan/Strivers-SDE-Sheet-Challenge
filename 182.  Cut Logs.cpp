#include<bits/stdc++.h>
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<int> dp(k+1,0);
    int mov = 0;
    while(dp[k]<n){
        mov++;
        for(int i=k;i>0;i--)
        dp[i] += 1+dp[i-1];
    }
    return mov;
}
