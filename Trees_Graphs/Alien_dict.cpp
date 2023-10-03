#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
    string findOrder(string dict[], int N, int K) {
       vector<vector<int>> adj(K);
       for(int i=0;i<N-1;i++){
           string s1=dict[i];
           string s2=dict[i+1];
           int len=min(s1.size(),s2.size());
           int it=0;
           while(it<len){
               if(s1[it]==s2[it]) it++;
               else{
                   adj[s1[it]-'a'].push_back(s2[it]-'a');
                   break;
               }
           }
       }
       
       vector<int> topo=topoSort(K,adj);
       string ans="";
       for(auto it:topo){
           ans+=(it+'a');
       }
       return ans;
    }
};