#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
    //Memoization
    int maxsum(int arr[],int n,vector<int> &dp ){
        if(n==0) return arr[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
         int pick=arr[n]+maxsum(arr,n-2,dp);
         int notpick=0+maxsum(arr,n-1,dp);
         dp[n]=max(pick,notpick);
         return dp[n];
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        int ans=maxsum(arr,n-1,dp);//stores ans from recursion memoization
        
        //Tabulation Space Optimisation

        int prev=arr[0];
        int prev2=0;
        int take,nottake;
        for(int i=1;i<n;i++){
            take=arr[i];
            if(i>1) take+=prev2;
            nottake=0+prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

