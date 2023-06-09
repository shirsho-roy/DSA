#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
map<int,int> vis;
void bfs(int src){
    vector<int> level;
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int curr=q.front();
        level.push_back(curr);
        q.pop();
        for(int child:adj[curr]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
            }
        }
    }
}