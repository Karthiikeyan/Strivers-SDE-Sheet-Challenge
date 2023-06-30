#include <bits/stdc++.h> 

bool palindrome(string &s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}

void solve(int ind, string &s, vector<string> &str, vector<vector<string>> &ans){
    if(ind==s.size()){
        ans.push_back(str);
        return;
    }

    for(int i=ind;i<s.size();i++){
        if(palindrome(s, ind, i)){
            str.push_back(s.substr(ind,i-ind+1));
            solve(i+1, s, str, ans);
            str.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> str;
    solve(0, s, str, ans);
    return ans;
}