#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &m)
{
    int r=m.size();
    int c=m[0].size();
    vector<int> row(r,-1),col(c,-1);
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]==0)
            {
                row[i]=0;
                col[j]=0;
                //mark the index of vector row and col 0,whenever you find a zero
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(row[i]==0 || col[j]==0)
            {
                m[i][j]=0;
            }
        }
    }

 
}