#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){
     if(n<=1){
        return n;
     }
     if(dp[n]!=-1) return dp[n];
     else{
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
     }
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int x=fib(n,dp);
    cout<<x<<endl;
}