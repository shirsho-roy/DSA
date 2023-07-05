#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Optimal Tabulation
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n,1);
       vector<int> cnt(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]>nums[prev])
                 {
                   if(dp[i]<1+dp[prev]) {
                      dp[i]=dp[prev]+1;
                      cnt[i]=cnt[prev];
                       }
                     else if(dp[i]==1+dp[prev]){
                         cnt[i]+=cnt[prev];
                     }
                 }
            }
        }
            int mx=INT_MIN;
            int id=0;
            int cntmx=0;
            for(int i=0;i<n;i++){
                if(mx<dp[i]) {
                    mx=dp[i];
                    cntmx=cnt[i];
                }
                else if(dp[i]==mx){
                    cntmx+=cnt[i];
                }
            }
            
            return cntmx;
        
    }
};