#include<bits/stdc++.h>

void dfs(int row, int col, int n, int m, vector<vector<int>> &ans,
 vector<vector<int>> &image, int newColor, int sColor, int drow[], int dcol[]){
    ans[row][col] = newColor;
    for(int i=0;i<4;i++){
        int row1 = row+drow[i];
        int col1 = col+dcol[i];
        if(row1>=0 && row1<n && col1>=0 && col1<m && image[row1][col1]==sColor
         && ans[row1][col1]!=newColor){
             dfs(row1, col1, n, m, ans, image, newColor, sColor, drow, dcol);
         }
    }
 }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> ans = image;
    int n = image.size();
    int m = image[0].size();
    int sColor = image[x][y];
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    dfs(x, y, n, m, ans, image, newColor, sColor, drow, dcol);
    return ans;
}