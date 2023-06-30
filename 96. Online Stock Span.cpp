#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int, int>> st;
    int n = price.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().second <= price[i]){
            st.pop();
        }

        if(st.empty()){
            ans.push_back(i+1);
            st.push({i,price[i]});
        }
        else{
            int res = st.top().first;
            ans.push_back(i-res);
            st.push({i, price[i]});
        }
    }
    return ans;
}