#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
 
vector<int> par(N);
vector<int> size(N);
void make(int v){
    par[v]=v;
    size[v]=1;
}
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

