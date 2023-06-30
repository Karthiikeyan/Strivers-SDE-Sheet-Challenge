#include<bits/stdc++.h>
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int ans = 0;
    int sum = 0;
    int i=0;
    int j=0;
    while(i<n){
        while(i<n && sum<=k){
            if(!arr[i]) sum++;
            if(sum > k) break;
            i++;
        }

        ans = max(ans,i-j);

        while(j<=i && sum>k){
            if(!arr[j]) sum--;
            if(sum<=k) break;
            j++;
        }
        i++;
        j++;
    }
    return ans;
}
