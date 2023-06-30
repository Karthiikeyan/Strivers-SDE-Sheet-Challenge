int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    int matrix[n+1][n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrix[i][j] = (i==j)?0:1e9;
        }
    }

    for(auto it: edges){
        matrix[it[0]][it[1]] = it[2];
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k && j!=k && matrix[i][k]!=1e9 && matrix[k][j]!=1e9){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }

    return matrix[src][dest];
}