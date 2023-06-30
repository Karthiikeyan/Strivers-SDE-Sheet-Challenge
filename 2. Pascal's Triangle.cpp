#include <bits/stdc++.h>

vector<long long> print_row(int row){
  vector<long long> ans_row;
  long long val = 1;
  ans_row.push_back(1);
  for(int col=1;col<row;col++){
    val = val*(row-col);
    val /= col;
    ans_row.push_back(val);
  }
  return ans_row;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>> ans;
  for(int i=1;i<=n;i++){
    ans.push_back(print_row(i));
  }
  return ans;
}
