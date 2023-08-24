#include <bits/stdc++.h>
using namespace std;

//Count number or subarrays with product less than k(all such)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n=nums.size();
      if(k<=1) return 0;
      int cnt=0;
      int l=0,r=0;
      int prod=1;
      while(r<n){
          prod*=nums[r];
          while(prod>=k){
              prod/=nums[l];
              l++;
          }
          cnt+=(r-l+1);
          r++;
      } 
      return cnt; 
    }
};