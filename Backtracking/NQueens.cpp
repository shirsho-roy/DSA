#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int col, vector<string> &board,int n,vector<vector<string>> &res,vector<int> &leftrow, vector<int> &ud, vector<int> &ld){
        if(col==n) {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && ud[n-1+col-row]==0 && ld[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                ud[n-1+col-row]=1;
                ld[row+col]=1;
                solve(col+1,board,n,res,leftrow,ud,ld);
                board[row][col]='.';
                leftrow[row]=0;
                ud[n-1+col-row]=0;
                ld[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> res;
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=(s);
         vector<int> leftrow(n);
         vector<int> ud(2*n-1);
         vector<int> ld(2*n-1);
         solve(0,board,n,res,leftrow,ud,ld);
         return res;
    }
};