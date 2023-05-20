#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//    vector<string> res;
    void solve(string s,string op,vector<string> &res){
        if(s.size()==0){
            res.push_back(op);
            return;
        }
        if(s[0]-'0'>=0 && s[0]-'0'<=9) {
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,op1,res);
        }
        else{
        string op2=op;
        op2.push_back(toupper(s[0]));
        string op3=op;
        op3.push_back(tolower(s[0]));
        s.erase(s.begin()+0);
        solve(s,op2,res);
        solve(s,op3,res);}
       
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string> res;
        string op="";
        solve(s,op,res);
        return res;
    }
};