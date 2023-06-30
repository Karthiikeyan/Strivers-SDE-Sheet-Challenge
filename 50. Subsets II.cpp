#include <bits/stdc++.h> 

void subsets(int ind, int n, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int i=ind;i<n;i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        subsets(i+1, n, ds, arr, ans);
        ds.pop_back();
    }
} 

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    subsets(0, n, ds, arr, ans);
    return ans;
}