#include<bits/stdc++.h>

void solution(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &left,
vector<int> &lowdig, vector<int> &uppdig){
    if(col==n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    for(int row=0;row<n;row++){
        if(board[row][col]==0 && left[row]==0 && lowdig[row+col]==0
        && uppdig[n-1 + col-row]==0){
            board[row][col] = 1;
            left[row] = 1;
            lowdig[row+col] = 1;
            uppdig[n-1 + col-row] = 1;
            solution(col+1, n, board, ans, left, lowdig, uppdig);
            board[row][col] = 0;
            left[row] = 0;
            lowdig[row+col] = 0;
            uppdig[n-1 + col-row] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<int> left(n, 0);
    vector<int> lowdig(2*n-1, 0);
    vector<int> uppdig(2*n-1, 0);
    solution(0, n, board, ans, left, lowdig, uppdig);
    return ans;
}