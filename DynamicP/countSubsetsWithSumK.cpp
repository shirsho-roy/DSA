//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int m=1e9+7;
    //Memoization
    int ans(int arr[], int sum, int i, vector<vector<int>>& dp){
        if(i==0){  //Only 1 base case as we have to travel to index==0 even if we get sum=0 so as to check for 0 element
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            else return 0;
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int not_pick=ans(arr, sum, i-1, dp);
        int pick=0;
        if(arr[i]<=sum)
            pick=ans(arr, sum-arr[i], i-1, dp);
        return dp[i][sum]=(not_pick%m+pick%m)%m;
    }
    //Tabulation
	int perfectSum(int a[], int n, int sum)
	{
       vector<vector<int>> dp(n,vector<int>(sum+1,0));
       for(int i=0;i<n;i++) {
          if(a[i]!=0)
             dp[i][0]=1;
          else dp[i][0]=2;
       }
           
       if(a[0]<=sum) {
           if(a[0]!=0)
             dp[0][a[0]]=1;
           else
             dp[0][a[0]]=2;
       }
           
       for(int i=1;i<n;i++){
           for(int tg=0;tg<=sum;tg++){
               int pick=0,notpick=0;
               notpick=dp[i-1][tg]%m;
               if(a[i]<=tg) pick=dp[i-1][tg-a[i]]%m;
               dp[i][tg]=pick+notpick;
           }
       }
       return dp[n-1][sum]%m;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends