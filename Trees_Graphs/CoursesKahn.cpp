#include<bits/stdc++.h>
using namespace std;
//Cycle detection using Kahn' algorithm(Compare Topsort number with no. of vertices)
class Solution {
public:
    bool isCycle(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        int c=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                c++;
            }
        }
        while(!q.empty()){
            int frnt=q.front();
            q.pop();
            for(auto it:adj[frnt]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    c++;
                }
            }

        }
        if(c==numCourses) return true;
        else return false;

    }
};