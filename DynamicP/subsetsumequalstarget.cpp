#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
  //Momoization
   int check(vector<int>&arr,int i, int sum,vector<vector<int>> dp){
        if(sum==0) return 1;
        if(i==0) return (int)(arr[i]==sum);
        
         if(dp[i][sum]!=-1) return dp[i][sum];
         
         bool take=false,nottake=false;
         if(arr[i]<=sum) take=check(arr,i-1,sum-arr[i],dp);
         nottake=check(arr,i-1,sum,dp);
        return dp[i][sum]=(int)(take or nottake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int s=0;
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        if(check(arr,arr.size()-1,sum,dp)==1) return true;
        else return false;
    }
   //Tabulation
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));
        int n=arr.size();
        for(int i=0;i<arr.size();i++) dp[i][0]=true;
        for(int i=0;i<=sum;i++) { if(i==arr[0]) dp[0][i]=true;}
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take||nottake;
            }
        }
        return dp[n-1][sum];
        
    }
    //Space Optimisation
    bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}


};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

