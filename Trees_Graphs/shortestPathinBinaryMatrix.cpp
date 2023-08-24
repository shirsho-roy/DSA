#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        int delrow[]={1,0,-1,0,1,-1,1,-1};
        int delcol[]={0,1,0,-1,1,1,-1,-1};
         if(grid[0][0]==0 and m==1 and n==1)
        {
            return 1;
        }
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int x=t.first;
            int y=t.second;
            if(x==n-1 && y==m-1) return dist[x][y];
            for(int i=0;i<8;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx>=0 && nx<=n-1 && ny>=0 && ny<=m-1 && grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny]=1;//marking visited so that it isn't retraversed
                    dist[nx][ny]=min(dist[nx][ny],dist[x][y]+1);
                }
            }
        }
        return -1;
    }
};