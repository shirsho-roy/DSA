#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    void solve(int k, int pos, vector<int> &v, int &ans){
        if(v.size()==1){
            ans = v[0];
            return;
        }
        
        pos = (k-1+pos)%v.size();
        v.erase(v.begin()+pos);
        solve(k, pos, v, ans);
    }
    
    int findJosephus(int n, int k) {
        int pos=0;
        int ans=0;
        vector<int> v;
        
        for(int i=0; i<n; i++){
            v.push_back(i+1);
        }
        
        solve(k, pos, v, ans);
        return ans;
    }
};