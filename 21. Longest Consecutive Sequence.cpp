#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if(n==0) return 0;
    unordered_set<int> set;
    int longest = 0;
    int cnt = 0;
    for(auto it:arr){
        set.insert(it);
    }

    for(auto it: set){
        if(set.find(it-1) == set.end()){
            int x = it;
            cnt = 1;
            while(set.find(x+1) != set.end()){
                x = x+1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}