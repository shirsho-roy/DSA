#include<bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int > v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cin>>k;
    int maxx=INT_MIN;
    int minn=INT_MAX;
    vector<int> ma;
    vector<int> mi;
    int ans=0;
    for(int i=0;i<n-1;i++){
        maxx=max(maxx,v[i]);
        ma.push_back(maxx);
    }
    for(int i=n-1;i>=1;i--){
        minn=min(minn,v[i]);
        mi.push_back(minn);
    }
    for(int i=0;i<n-1;i++){
        if(ma[i]+mi[n-2-i]>=k){
            ans++;
        }
    }
    if(ans==0){
        cout<<-1<<endl;
    }
    else{
    cout<<ans<<endl;
    }
    return 0;
}