#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Bottom Up Approach
    int costing(int n, vector<int> & dp,vector<int>& cost){
         if(n==cost.size()-1) return dp[cost.size()-1]=cost[n];
         if(n==cost.size()-2) return dp[cost.size()-2]=cost[n];
         if(dp[n]!=-1){
             return dp[n];
         }
         int p1=costing(n+1,dp,cost)+cost[n];
         int p2=costing(n+2,dp,cost)+cost[n];
         dp[n]=min(p1,p2);
         return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        int n;
         int ans1=costing(0,dp,cost);
         int ans2=costing(1,dp,cost);
         return min(ans1,ans2);
    }
};