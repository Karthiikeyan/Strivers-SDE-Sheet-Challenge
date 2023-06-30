#include<bits/stdc++.h>

// int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
// 	if(i<0 || j<0) return 0;

// 	if(s[i]==t[j]) return 1+f(i-1, j-1, s, t, dp);
// 	if(dp[i][j]!= -1) return dp[i][j];
// 	return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
// }

// int lcs(string &s, string &t)
// {
// 	//Write your code here
// 	int n = s.size();
// 	int m = t.size();
// 	vector<vector<int>> dp(n, vector<int> (m, -1));
// 	return f(n-1, m-1, s, t, dp);
// }

// int longestPalindromeSubsequence(string &s)
// {
//     // Write your code here.
//     string t = s;
//     reverse(t.begin(), t.end());
//     return lcs(s, t);
// }

int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.size();
	int i = 0, j = n - 1, count = 0, temp = j;
	while(i < j) {
		if(str[i] == str[j])
			i++, j--;
		else {
			count++;
			i = 0, temp--;
			j = temp;
		}
	}	
	return count;
	
}
