#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int num = 0;
    for(auto it: str){
        if(isdigit(it))
            num = (num*10) + (it-'0');
    }
    return str[0]=='-'? -num : num;
    
}