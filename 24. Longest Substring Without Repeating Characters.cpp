#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    vector<int> mp(n, -1);
    
    int left = 0;
    int right = 0;
    int len = 0;

    while(right<n){
        if(mp[input[right]]!=-1) left = max(mp[input[right]]+1, left);
        mp[input[right]] = right;
        len = max(len, right-left+1);
        right++;
    }
    return len;

}