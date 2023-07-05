#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(arr[i]>arr[prev])
                 {
                   if(dp[i]<1+dp[prev]) {
                       hash[i]=prev;
                       dp[i]=max(dp[i],1+dp[prev]);}
                 }
            }
        }
        int mx=INT_MIN,id;
        for(int i=0;i<n;i++){
            if(dp[i]>mx){
                mx=dp[i];
                id=i;
            }
        }
        vector<int> lis;
        while(id!=hash[id]){
            lis.push_back(arr[id]);
            id=hash[id];
        }
        lis.push_back(arr[id]);
        reverse(lis.begin(),lis.end());
        return lis;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
