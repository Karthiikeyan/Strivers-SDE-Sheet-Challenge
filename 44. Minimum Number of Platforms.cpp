#include<bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);

    int platform = 1;
    int i=1;
    int j=0;
    while(i<n){
        if(at[i]<=dt[j]){            
            platform++;
        }
        else{
            j++;
        }
        i++;
    }
    return platform;

}