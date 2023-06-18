#include <bits/stdc++.h>
using namespace std;

class Solution{
public:


//Memoization
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector
<int>>& dp){

    if(ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}


   //Tabulation
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        for(int w=wt[0];w<=W;w++){
            dp[0][w]=(w/wt[0])*val[0];
        }
        for(int i=0;i<N;i++){
            dp[i][0];
        }
        for(int i=1;i<N;i++){
            for(int t=0;t<=W;t++){
                int notpick=0+dp[i-1][t];
                int pick=0;
                if(wt[i]<=t) pick=val[i]+dp[i][t-wt[i]];
                dp[i][t]=max(pick,notpick);
            }
        }
        return dp[N-1][W];
    }

   //Space Optimisation
    int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
         vector<int> cur(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        cur[i] = ((int)i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = cur[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
    }
    
    return cur[W];

}
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
} 
