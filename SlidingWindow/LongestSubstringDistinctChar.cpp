#include<bits/stdc++.h>
using namespace std;

int LongestSubstring(string s){
    int n=s.size();
    map<char,int> st;
    int cnt=0,mxlen=0;
    int l=0,r=0;
    while(r<n){
        st[s[r]]++;
        cnt=st.size();
        if(cnt==r-l+1){
            mxlen=max(mxlen,cnt);
        }
        else if(r-l+1>cnt){
        while(cnt!=r-l+1){
            st[s[l]]--;
            if(st[s[l]]==0) st.erase(s[l]);
            l--;
        }
        }
        r++;
    }
    return mxlen;
}