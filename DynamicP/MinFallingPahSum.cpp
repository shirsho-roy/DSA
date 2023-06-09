#include <bits/stdc++.h>
using namespace std;
//Memoizations
int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>> &dp){
         if(i==0) return matrix[0][j];
         if(j<0 ||j>=matrix.size()) return 1e9;

         if(dp[i][j]!=-1) return dp[i][j];
         vector<int> paths(3,1e9);
         paths[0]=matrix[i][j]+dfs(matrix,i-1,j,dp);
         if(j>0) paths[1]=matrix[i][j]+dfs(matrix,i-1,j-1,dp);
         if(j<matrix.size()-1) paths[2]=matrix[i][j]+dfs(matrix,i-1,j+1,dp);
         int mn=INT_MAX;
         for(auto it:paths){
            mn=min(mn,it);
         }
         return dp[i][j]=mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1)) ;  
        int mxs[m];
        int res=INT_MAX;
        for(int i=0;i<m;i++){
           mxs[i]=dfs(matrix,n-1,i,dp);
           res=min(res,mxs[i]);
        }
        return res;
     }
     //tabulation
     int minfallingpathSum(vector<vector<int>>& matrix){
         int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1)) ; 
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                vector<int> paths(3,1e9);
                paths[0]=matrix[i][j]+dp[i-1][j];
                if(j>0) paths[1]=matrix[i][j]+dp[i-1][j-1];
              if(j<matrix.size()-1) paths[2]=matrix[i][j]+dp[i-1][j+1];
             int mn=INT_MAX;
             for(auto it:paths){
               mn=min(mn,it);
         }
             dp[i][j]=mn;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
     }
    //Space Optimisaton
    int getMinPathSum(vector<vector<int> > &matrix){
    
     int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m,0), cur(m,0);
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            cur[j] = min(up, min(leftDiagonal,rightDiagonal));
            
        }
        
        prev = cur;
    }
    
    int mi = INT_MAX;
    
    for(int j=0; j<m;j++){
        mi = min(mi,prev[j]);
    }
    
    return mi;

}