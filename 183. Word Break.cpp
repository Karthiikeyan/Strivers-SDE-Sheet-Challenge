#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    set<string> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    int i=0;
    string temp = "";
    int ind = -1;
    while(i<target.size()){
        temp += target[i];
        if(st.find(temp)!=st.end()){
            ind = i;
            temp = "";
        }
        i++;
    }
    if(ind==target.size()-1) return true;
    return false;
}