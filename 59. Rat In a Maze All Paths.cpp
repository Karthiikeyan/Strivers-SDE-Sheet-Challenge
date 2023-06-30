#include <bits/stdc++.h> 
using namespace std;
void solve(int row, int col, vector<vector<int> > &maze, int n, vector<vector<int>>&vis,
 vector<vector<int>> &ans){
  // if(row<0 || col<0 && row>=n || col>=n) return;
  if(row==n-1 && col==n-1){
    vector<int> temp;
    vis[row][col] = 1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        temp.push_back(vis[i][j]);
      }
    }
    vis[row][col] = 0;
    ans.push_back(temp);
    return;
  }

  int drow[4] = {-1, 0, 1, 0};
  int dcol[4] = {0, 1, 0, -1};

  for(int i=0;i<4;i++){
    int row1 = row+drow[i];
    int col1 = col+dcol[i];
    if(row1>=0 && row1<n && col1>=0 && col1<n && vis[row1][col1]!=1 && maze[row1][col1]==1){
      vis[row1][col1] = 1;
      solve(row1, col1, maze, n, vis, ans);
      vis[row1][col1] = 0;
    }
  }

}

vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> vis(n, vector<int>(n,0));
  vector<vector<int>> ans;
  if(maze[0][0]==1){
    vis[0][0] = 1;
    solve(0, 0, maze, n, vis, ans);
  } 
  return ans;
}