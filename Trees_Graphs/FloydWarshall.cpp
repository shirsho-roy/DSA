#include <bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> mat(n+1,vector<int>(n+1,1e9));
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        mat[u][v]=w;
    }
    for(int i=1;i<=n;i++){
        mat[i][i]=0;
    }
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mat[via][j]==1e9 || mat[i][via]==1e9){
                    mat[i][j]=min(mat[i][j],1000000000);//as negative numbers may decrease infinite path length(which actually represents no path)
                }
                else
                  mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
            }
        }
    }
    return mat[src][dest];

    //detect -ve cycles
    for(int i=1;i<=n;i++){
        if(mat[i][i]<0) cout<<"Negative Cycle"<<endl;
    }
}