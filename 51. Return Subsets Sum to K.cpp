#include<bits/stdc++.h>

void f(int ind, int sum, vector<int> &arr, int n, int k,
 vector<vector<int>> &ans, vector<int> &temp){
    if(ind==n){
        if(sum == k)
        ans.push_back(temp);
        return;
    }
    f(ind+1, sum, arr, n, k, ans, temp);
    temp.push_back(arr[ind]);
    f(ind+1, sum+arr[ind], arr, n, k, ans, temp);
    temp.pop_back();
 }

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    f(0, 0, arr, n, k, ans, temp);
    return ans;
}