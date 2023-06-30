#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    multiset<int> st;
    vector<int> ans;
    for(auto it: kArrays){
        for(auto i: it){
            st.insert(i);
        }
    }
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
    

}
