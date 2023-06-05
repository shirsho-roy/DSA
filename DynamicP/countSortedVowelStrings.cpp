#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int vwel(int n,int i, vector<vector<int>> &dp){
        //the moment is n reduce to 0 we et the required set and we can  count 1
         if(n==0) return 1;
         if(i>=5) return 0;//No further vowels
         int pick,notpick;
        if(dp[n][i]!=-1) return dp[n][i];
         pick=vwel(n-1,i,dp);
         notpick=vwel(n,i+1,dp);
        return dp[n][i]=pick+notpick;
    }
    int countVowelStrings(int n) {
         vector<vector<int>> dp( n+1 , vector<int> (5, -1));
         int ans=vwel(n,0,dp);
         return ans;
    }
};