#include <bits/stdc++.h>
using namespace std;
//Memoization
int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}

//Tabulation (Intutitive)
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=-1;prev--){
            int nottake=0+dp[i+1][prev+1];
            int take=INT_MIN;
            if(prev==-1 || arr[prev]<arr[i]) take=1+dp[i+1][i+1];
            dp[i][prev+1]=max(nottake,take);
        }
    }
    return dp[0][-1+1];
}
 
 //Binary Search method
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           // arr[i] > the last element of temp array 
           
           temp.push_back(arr[i]);
           len++;
           
        } 
        else{
	// replacement step
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
        
    }
    
    return len;
}