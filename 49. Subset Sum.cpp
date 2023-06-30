#include <bits/stdc++.h> 

void subset(int ind, int sum, int n, vector<int> &num, vector<int> &ans){
    if(ind==n){
        ans.push_back(sum);
        return;
    } 

    subset(ind+1, sum+num[ind], n, num, ans);
    subset(ind+1, sum, n, num, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n = num.size();
    subset(0, 0, n, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}