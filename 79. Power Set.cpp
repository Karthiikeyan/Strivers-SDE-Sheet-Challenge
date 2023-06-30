#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here\
    
    vector<int> s;
    vector<vector<int>> ans;
    int n = v.size();
    for(int i=0;i<(1<<n);i++){
        s.clear();
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            s.push_back(v[j]);
        }
        if(s.size()>0)
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    return ans;
}