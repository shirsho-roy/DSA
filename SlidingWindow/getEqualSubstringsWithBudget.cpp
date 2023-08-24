#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int m) {
        int l=0;
        int r=0;
        int n=s.size();
        int cost=0;
        int mxlen=0;
        while(r<n){
            cost+=abs(s[r]-t[r]);
            if(cost<=m){
                r++;
                mxlen=max(mxlen,r-l);
            }
            else{
                while(cost>m){
                    cost-=abs(s[l]-t[l]);
                    l++;
                }
                r++;
            }
        }
        return mxlen;
    }
};