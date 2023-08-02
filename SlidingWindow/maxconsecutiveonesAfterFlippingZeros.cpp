#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int cones=0,czero=0;
       int s=0;int e=0;
       int mx=INT_MIN;
       while(e<nums.size()){
           if(nums[e++]==1) cones++;
           else czero++;
           while(czero>k){
               if(nums[s]==1) cones--;
               else czero--;
               s++;
           }
           mx=max(mx,czero+cones);
       } 
       return mx;
    }
};