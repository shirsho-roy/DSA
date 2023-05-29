#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count(int n,vector<int> &dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        else{
            dp[n]=count(n-1,dp)+count(n-2,dp);
            return dp[n];
        }
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=count(n,dp);
        return ans;
    }
};