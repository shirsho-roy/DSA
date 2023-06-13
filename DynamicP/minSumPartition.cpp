//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	   //int n=nums.size();
      int S=0;
      for(int i=0;i<n;i++)  S+=nums[i];
      vector<vector<bool>> dp(n, vector<bool>(S+1,0));
      if(nums[0]<=S) dp[0][nums[0]]=1;
      for(int i=0;i<n;i++) dp[i][0]=1;
    for(int i=1;i<n;i++){
        for(int tg=1;tg<=S;tg++){
            bool nottake=dp[i-1][tg];
            bool take=0;
            if(nums[i]<=tg) take=dp[i-1][tg-nums[i]];
            dp[i][tg]=take or nottake;
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<=S;i++){
        if(dp[n-1][i]==1)
           mini=min(mini,abs(2*i-S));
    }
    return mini;
    }
};

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}