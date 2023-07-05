#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	void LIS(vector<int> &nums,vector<int> &dp ){
	    int n=nums.size();
      
       
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]>nums[prev])
                 {
                   if(dp[i]<1+dp[prev]) {
            
                       dp[i]=max(dp[i],1+dp[prev]);}
                 }
            }
        }
        
	}
	int LongestBitonicSequence(vector<int>nums)
	{   int n=nums.size();
	    vector<int> dp1(n,1);
	     vector<int> dp2(n,1);
	     LIS(nums,dp1);
	   //  reverse(nums.begin(),nums.end());
	   vector<int> rev(n);
	   for(int i=0;i<n;i++){
	       rev[i]=nums[n-1-i];
	   }
	     LIS(rev,dp2);
	     vector<int> bitonic(n);
	     reverse(dp2.begin(),dp2.end());
	     for(int i=0;i<n;i++){
	       bitonic[i]=dp1[i]+dp2[i]-1;  
	     }
	     return *max_element(bitonic.begin(),bitonic.end());
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}