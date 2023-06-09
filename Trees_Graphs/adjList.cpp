#include<bits/stdc++.h>
using namespace std;
 
void create_adjList(vector<pair<int,int>> &adj,int n,int e){
    //here e=n-1 for trees
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adj.push_back(make_pair(u,v));
    }

}