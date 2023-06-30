#include<bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string text, string pattern) {
    vector<int> ans; 
    
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        bool flag = true;
        
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back(i + 1);  
        }
    }
	return ans;
}
