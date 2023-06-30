#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        long long int l=1;
        long long int h=1e9; //h=*max_element(pile.begin(),piles.end())
        int req=0;
        while(l<=h){
          long long int mid=l+(h-l)/2;
          long long int cnt=0;
          for(int i=0;i<piles.size();i++){
              cnt+=ceil(1.0 * piles[i]/mid);
             
          }
          if(cnt==hr) {
              req=mid;
              h=mid-1;
          }
          else if(cnt>hr){
              l=mid+1;
          }
          else{ 
              req=mid;
              h=mid-1;
          }
        }
        return req;
    }
};