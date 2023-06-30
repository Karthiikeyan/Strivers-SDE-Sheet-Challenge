#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    map<int,int> mp;
    int xr = 0;
    mp[xr]++;
    int cnt = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        xr ^= arr[i];
        int x = xr^k;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}