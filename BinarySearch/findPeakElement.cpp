#include <bits/stdc++.h>
using namespace std;
 int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int mid;
        int n=nums.size();
        while(l<h)
        {
            mid=l+(h-l)/2;
            if(mid-1>=0 && mid+1<=n-1)
            {  if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                   return mid;
               else if(nums[mid]>nums[mid+1])//Decreasing on right->Peak to left of mid
                   h=mid;
               else   //Increaing on right-> Peak to the right
                   l=mid+1;
            }
            if(mid==0 && nums[mid]>nums[mid+1])
                 return 0;
            if(mid==0 && nums[mid]<nums[mid+1])
                 l=mid+1;
            if(mid==n-1 && nums[mid]>nums[mid-1])
                return n;
            if(mid==n-1 && nums[mid]<nums[mid-1])
                h=mid;
        }
        return l;
    }