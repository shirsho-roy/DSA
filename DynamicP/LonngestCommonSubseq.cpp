#include <bits/stdc++.h>
using namespace std;
//Memoize
 int solver(int ind1,int ind2,string text1, string text2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2]; 
        if(text1[ind1]==text2[ind2]) dp[ind1][ind2]=1+solver(ind1-1,ind2-1,text1,text2,dp);
        else{
            dp[ind1][ind2]=0+max(solver(ind1,ind2-1,text1,text2,dp),solver(ind1-1,ind2,text1,text2,dp));
        }
        return dp[ind1][ind2];

    }
  //Tabulation
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        int n=text1.size();
        int m=text2.size();
        // return solver(n-1,m-1,text1,text2,dp);
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       return dp[n][m];
    }