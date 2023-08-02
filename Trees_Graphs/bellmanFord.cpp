#include<bits/stdc++.h>
using namespace std;
void bellmanford(vector<pair<pair<int,int>,int>> edges,int V){
         vector<int> dist(V,1e9);
         dist[0]=0;
         for(int i=1;i<V;i++){ //Need to traverse edges for each and every vertex except source
            for(auto e:edges){
                int u=e.first.first;
                int v=e.first.second;
                int wt=e.second;
                if(dist[u]!=1e9 && dist[v]>wt+dist[u]){
                    dist[v]=wt+dist[u];
                }
            }
         }

         //Check for Negative Cycle
         for(auto e:edges){
                int u=e.first.first;
                int v=e.first.second;
                int wt=e.second;
                if(dist[u]!=1e9 && dist[v]>wt+dist[u]){
                    cout<<"Negative Cycle";//as dist further decreses below min due to negative edge
                    return;
                }
            }

}