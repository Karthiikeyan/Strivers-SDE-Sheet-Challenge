#include<bits/stdc++.h>


int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int not_rotton = 0;
    int vis[n][m];
    queue<pair<pair<int, int>, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                vis[i][j] = 2;
                q.push({{i,j},0});
            }
            else{
                vis[i][j] = 0;
            }
            if(grid[i][j]==1)
            not_rotton++;
        }
    }

    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,-1,0,1};

    int rotton = 0;
    int max_time = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        max_time = max(max_time, time);

        for(int i=0;i<4;i++){
            int row1 = row + drow[i];
            int col1 = col + dcol[i];
            if(row1>=0 && col1>=0 && row1<n && col1<m && grid[row1][col1]==1 && vis[row1][col1]==0){
                vis[row1][col1] = 2;
                q.push({{row1,col1},time+1});
                rotton++;
            }
        }
    }
    
    if(not_rotton == rotton) return max_time;
    return -1;

}