#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
     int solve(string word1, string word2,int i,int j,vector<vector<int>> &dp){
         if(i<0) return j+1; //return whatevr is left of word2 to be added
         if(j<0) return i+1; //return whatever is left of word1 to be del
         if(dp[i][j]!=-1) return dp[i][j];
         int mn=INT_MAX;
         if(word1[i]==word2[j]) 
            dp[i][j]=0+solve(word1,word2,i-1,j-1,dp);
         else{
             int ins=1+solve(word1,word2,i,j-1,dp);//Insert in word1 to equalise
             int del=1+solve(word1,word2,i-1,j,dp); //Delete extra letter in word1
             int replace=1+solve(word1,word2,i-1,j-1,dp); //Replace the letter of word1 with that of word2
              
              mn=min(ins,min(del,replace));
              dp[i][j]=mn;}
              return dp[i][j];
         
     }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int ans=solve(word1,word2,n-1,m-1,dp);
        return ans;
    }
};