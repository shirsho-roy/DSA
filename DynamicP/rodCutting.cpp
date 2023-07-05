#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  //Tabulation
    int cutRod(int price[], int n) {
       vector<vector<int>> dp(n,vector<int>(n+1,0));
       for(int t=0;t<=n;t++){
           dp[0][t]=t*price[0];
       }
       for(int i=0;i<n;i++) dp[i][0]=0;
       for(int i=1;i<n;i++){
           for(int t=0;t<=n;t++){
               int notpick=dp[i-1][t];
               int pick=0;
               if(i+1<=t) pick=price[i]+dp[i][t-1-i];
               dp[i][t]=max(pick,notpick);
           }
       }
       return dp[n-1][n];
    }
    

   //2 array Space Optimisation
     int cutRod(vector<int>& price,int N) {
    vector<int> prev (N+1,0);
    
    for(int i=0; i<=N; i++){
        prev[i] = i*price[0];//for 0th row
    }
    for(int ind=1; ind<N; ind++){
        vector<int> cur (N+1,0);
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + prev[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + prev[length-rodLength];
             cur[length] = max(notTaken,taken);   
        }
        prev=cur;
    }
    
    return prev[N];
}


  //1 array Space Optimisation
    int cutRod(vector<int>& price,int N) {
    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];//for 0th row
    }
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);  //cur length itself for the current row as prev one won't be needed anymore 
        }
    }
    
    return cur[N];
}
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        // cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}