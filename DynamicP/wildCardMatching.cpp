#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isstars(string p,int lim){
        for(int i=0;i<=lim;i++){
            if(p[i]!='*') return false;
        }
        return true;
    }
    bool solver(string s, string p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0) {
            if(isstars(p,j)) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            dp[i][j]=solver(s,p,i-1,j-1,dp); //match chars
        }
        else{
            if(p[j]=='*') dp[i][j]=solver(s,p,i-1,j,dp) || solver(s,p,i,j-1,dp);
                //If P[j] is star you may match seq of string of s with it or just ignore it
            else dp[i][j]=false;
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solver(s,p,n-1,m-1,dp);
    }
};