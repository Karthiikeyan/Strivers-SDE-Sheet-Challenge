#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=n-1;i>=0;i--){
        int element = arr[i];
        while(!st.empty() && st.top()>=element){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(element);
    }
    return ans;
}