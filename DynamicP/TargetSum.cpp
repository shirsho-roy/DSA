#include<bits/stdc++.h> 
using namespace std; 
int mod=1e9+7;
 //Memoization
 int dpmem(int i,int tg,vector<unordered_map<int,int>>&dp,vector<int>& nums){  //As target can be negative use map for target indexing instead of vector
         if(i<=0){
             
             if(tg-nums[i]==0 && tg+nums[i]==0) return 2;
             else if(tg-nums[i]==0 || tg+nums[i]==0) return 1;
             else return 0;
         }
         if(dp[i][tg]) return dp[i][tg];
          
          int plus=dpmem(i-1,tg-nums[i],dp,nums);
          int minus=dpmem(i-1,tg+nums[i],dp,nums);
         return dp[i][tg]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        
        int res=dpmem(nums.size()-1,target,dp,nums);
        return res;
    }
  

  //Tabulating: Method of finding partitions with given differnce
  int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int targetSum(int n, int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target <0 || (totSum-target)%2 ) return 0;
    
    return findWays(arr,(totSum-target)/2);
}
  
