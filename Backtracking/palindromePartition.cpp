#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> v;
    bool isPalindrome(string s,int f,int e ){
        while(f<=e){
            if(s[f++]!=s[e--]) return false;
        }
        return true;
    }
    void partition(int ind,vector<string> &p,vector<vector<string>> &res,string s){
        if(ind==s.size()){
            res.push_back(p);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                p.push_back(s.substr(ind,i-ind+1));
                partition(i+1,p,res,s);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        partition(0,p,res,s);
        return res;
    }
};