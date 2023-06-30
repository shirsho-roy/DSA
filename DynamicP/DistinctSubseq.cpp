#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>>dp(s.size()+1,vector<unsigned int>(t.size()+1));
        long long int n=s.size();
        long long int m=t.size();
        for(int i=0;i<=n;i++){
           dp[i][0]=1;
        }
        for(unsigned int i=1;i<=n;i++){
            for(unsigned int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};