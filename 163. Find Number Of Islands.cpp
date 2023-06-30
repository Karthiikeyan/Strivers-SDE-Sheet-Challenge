void dfs(int row, int col,  int** arr, int n ,int m){
   if(row<0 || col<0 || row>=n || col>=m || arr[row][col]!=1) 
   return;

   int drow[8] = {-1,0,1,0,-1,-1,1,1};
   int dcol[8] = {0,1,0,-1,-1,1,-1,1};
   
   arr[row][col] = 0;
   for(int i=0;i<8;i++){
      int row1 = row+drow[i];
      int col1 = col+dcol[i];
      dfs(row1, col1, arr, n, m);
   }

}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int island = 0;
   
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]!=0){
            dfs(i, j, arr, n, m);
            island++;
         }
      }
   }
   return island;

}
