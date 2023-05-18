#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int N =1e5+10;
vector<int> par;
vector<int> size;
   int find(int v){
    //Path Compression

    if(par[v]==v) return v;
    par[v]=find(par[v]);
    return find(par[v]);
}
void Union(int a,int b){
    //Union on basis of size- add smaller tree to larger

    int pa=find(a);
    int pb=find(b);
    if(pa!=pb){
        if(size[pa]<size[pb]){
            swap(pa,pb);
        }
        par[pb]=pa;
        size[pa]+=size[pb];
    }
}

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
               int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
               edges.push_back({d,{i,j}});
            }
            
        }
        sort(edges.begin(),edges.end());
        for(int i=0;i<points.size();i++){
            par.push_back(i);
            size.push_back(1);
        }
        int tot_cost=0;
        for(auto edge:edges){
            int ds=edge.first;
            int u=edge.second.first;
            int v=edge.second.second;
            if(find(u)==find(v)) continue;
            Union(u,v);
            tot_cost+=ds;
        }
        return tot_cost;
    }
};