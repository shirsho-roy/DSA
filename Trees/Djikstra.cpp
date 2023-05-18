#include<bits/stdc++.h>
using namespace std;
// n-nodes
//e-edges
int n,e;
vector<vector<pair<int,int>>> gp(n+1);
vector<int> djikstra(int src){
 vector<int> dist(n+1);
 vector<int> vis(n+1);
 multiset<pair<int,int>> st;
   dist[src]=0;
   st.insert({dist[src],src});
   //Dont mark visited now, rather mark it when item is taken out of set
   while(!st.empty()){
    auto top=*(st.begin());
    int node=top.second;
    int d=top.first;
    st.erase(st.begin());
    if(vis[node]==1) continue;
      vis[node]=1;
    for(auto child:gp[node]){
         int child_nd=child.second;
         if(dist[child_nd]>dist[node]+child.first){
            dist[child_nd]=dist[node]+child.first;
            st.insert({dist[child_nd],child_nd});
         }
    }
   }
     return dist; 
}