#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Tabulation like that of subsequemce
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }
                else dp[i][j]=0; //dp[i][j] here indicates the length of longest subarray ending at index i of the num1 and index j of nums2
            }
        }
        return mx;
    }
};