#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void solve(int c,int o,string op,vector<string> &res){
      if(c==0 && o==0){
          res.push_back(op);
          return;
      }
      if(o!=0) {
          string op3=op+'(';
          solve(c,o-1,op3,res);
      }
      if(c>o){
          string op2=op+')';
          solve(c-1,o,op2,res);
    
      }
      
  }
    vector<string> generateParenthesis(int n) {
        int c=n;int o=n;
        string op="";
        vector<string> res;
        solve(c,o,op,res);
        return res;
    }
};