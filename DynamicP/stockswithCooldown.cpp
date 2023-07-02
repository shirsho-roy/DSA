#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 //Memoization
    int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp ){

    if(ind>=n) return 0; //base case as it can exceed n to n+1
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind]+getAns(Arr,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind]+getAns(Arr,ind+2,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


//Tabulation
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2)); //As it can jump upto n+1
        dp[n][0]=0;
        dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
           dp[i][1]=max(-1*prices[i]+dp[i+1][0],dp[i+1][1]);
           dp[i][0]=max(prices[i]+dp[i+2][1],dp[i+1][0]); //Cooldown after sell so +2
        }
        return dp[0][1];
    }
};