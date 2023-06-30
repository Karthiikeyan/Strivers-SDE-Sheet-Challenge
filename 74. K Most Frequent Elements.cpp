#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    map<int,int> mpp;
    
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    priority_queue<pair<int,int>> pq;
    for(auto freq: mpp){
        pq.push({freq.second,freq.first});
    }

    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}