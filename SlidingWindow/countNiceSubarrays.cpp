#include <bits/stdc++.h>
using namespace std;

//Count number of All Subarrays with exactly k odd numbers
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        int c1=0;
        int c2=0;
        while(r<n){
           if(nums[r]%2!=0) cnt++;
           while(cnt>k){
               if(nums[l]%2!=0) cnt--;
               l++;
           }
           c1+=(r-l+1);//Counts all subarrays with odd numbers upto k(also less than k)
           r++;
        }
        l=0;
        r=0;
        cnt=0;
        while(r<n){
           if(nums[r]%2!=0) cnt++;
           while(cnt>k-1){
               if(nums[l]%2!=0) cnt--;
               l++;
           }
           c2+=(r-l+1);//Counts all subarrays with odd numbers upto k-1(also less than k-1)
           r++;
        }
       return c1-c2;
    }
};