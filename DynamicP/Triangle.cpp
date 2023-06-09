#include <bits/stdc++.h>
using namespace std;
//Memoization
int minSumPathUtilTriangle(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==matrix.size()-1)
    return matrix[i][j];
 //No need for out of bound condition
  if(dp[i][j]!=-1) return dp[i][j];
    
  int down = matrix[i][j]+minSumPathUtilTriangle(i+1,j,matrix,dp);
  int diag = matrix[i][j]+minSumPathUtilTriangle(i+1,j+1,matrix,dp);
  
  return dp[i][j] = min(down,diag);
  
}

//Tabulations
int minSumPathtriangle(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(n,0));
    for(int i=0;i<matrix.size();i++){
        dp[matrix.size()-1][i]=matrix[matrix.size()-1][i];//initialise from top
    }
    for(int i=n-1; i>=0 ; i--){
        for(int j=i; j>=0; j--){
            
                
                int down = matrix[i][j];
                 down += dp[i+1][j];
            
                int diag = matrix[i][j];
                diag+=dp[i+1][j+1];
                
                
                dp[i][j] = min(down,diag);//storing min path of up and  left
            
        }
    }
    
    return dp[0][0];
    
}
//Bottom up Tabulation(**Important)
int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int down=1e9;
                if(j<i) down=triangle[i][j]+dp[i-1][j];
                int diag=1e9;
                if(j>0) diag=triangle[i][j]+dp[i-1][j-1];
                dp[i][j]=min(down,diag);
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
           mn=min(dp[n-1][i],mn);
        }
        return mn;
    }
//Sapace Optimistion

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    
    return front[0];
    
}
