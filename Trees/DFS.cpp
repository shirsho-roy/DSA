#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
 void dfs(int vertex,int par=-1){
   
   for(auto child:adj[vertex]){

      if(child==par) continue;

      dfs(child,vertex);
   }  
 }