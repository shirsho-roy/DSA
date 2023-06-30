#include<bits/stdc++.h> 
using namespace std; 

class Solution{
 public:
    //Memoization
  int maxProf(int ind,int buy,vector<int> &prices,vector<vector<int>> &profit){
      if(ind==prices.size()) return 0;
       if(profit[ind][buy]!=-1) return profit[ind][buy];

       if(buy){
        profit[ind][buy]=max(-1*prices[ind]+maxProf(ind+1,0,prices,profit),maxProf(ind+1,1,prices,profit));
       }
       else{
         profit[ind][buy]=max(prices[ind]+maxProf(ind+1,1,prices,profit),maxProf(ind+1,0,prices,profit));
       }
       return profit[ind][buy];
  }
  //Tabulation
  int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0; //0:cannot buy
        dp[n][1]=0; //1:can buy
     
        for(int i=n-1;i>=0;i--){
           //Can buy
          dp[i][1]=max(-1*prices[i]+dp[i+1][0],0+dp[i+1][1]);
          //cannot buy
          dp[i][0]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
        }
        return dp[0][1];
    }
};