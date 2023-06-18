// {7,8,9,2,3,4,5}:2 is pivot
//[4,5,6,7,0,1,2] :0 is pivot
//[6,7,8,1]:pivot =1
#include <bits/stdc++.h>
using namespace std;
//For all array elements unique
//Search for pivot first
int pivotsearch(vector<int> &v){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
         if(l==h) return l;
         
         else if(v[mid]>v[h]){ //Left Sorted: pivot is mid or to right
           l=mid+1;
         }
         else if(v[mid]<=v[h]){ //right sorted :Pivot can be mid or to left
           h=mid;
         }
    }
    return h;
}
// Search on basis of Pivot
int rotsearch(vector<int> &nums,int tg){
   int pivot=pivotsearch(nums);
    int l,h;
    int mid;
    if(nums.size()==1){
      if(tg==nums[0]) return 0;
      else return -1;
    }
    if(nums.size()==2){
      if(tg==nums[0]) return 0;
      else if(tg==nums[1]) return 1;
      else return -1;
    }
    
    if(tg>=nums[pivot] && tg<=nums[nums.size()-1]){ //in right sorted part
         l=pivot;
         h=nums.size()-1;
         while(l<=h){
             int mid=l+(h-l)/2;
             if(nums[mid]==tg) return mid;
             else if(nums[mid]>tg) h=mid-1;
             else l=mid+1;
         }
         return -1;
    }
    
     else if(pivot!=0 && tg>=nums[0] && tg<=nums[pivot-1]){  //In left sorted arr
         l=0;
         h=pivot-1;
           while(l<=h){
             int mid=l+(h-l)/2;
             if(nums[mid]==tg) return mid;
             else if(nums[mid]>tg) h=mid-1;
             else l=mid+1;
         }
         return -1;
    }
    
    else return -1;
}



//Better Approach
int search(vector<int>& v, int target) {
       int l=0,h=v.size()-1,mid;
        int N=v.size();
        while(l<=h)
        {  mid=(l+h)/2;
           if(v[mid]==target) 
                 return mid;
           else if(v[mid]>=v[h])//left array sorted till mid
           { if(target >= v[l] && target < v[mid]) //checks for target in left sorted part
                  h=mid-1;
             else
                  l=mid+1;  
           }
           else if(v[mid]<=v[h])//Right array sorted from mid
           { if(target >= v[mid] && target <= v[h]) //Checks for Target in Right sorted part
                    l=mid+1;
             else
                    h=mid-1;
           } 
        }
        return -1;
    }



    //For array having duplicate elements

    bool searchrot(vector<int>& v, int target) {
       int l=0,h=v.size()-1,mid;
        int N=v.size();
        while(l<=h)
        {  mid=(l+h)/2;
           if(v[mid]==target) 
                 return true;
           if(v[mid]==v[l] && v[mid]==v[h]){  // Additional condition for [3,4,5,3,3,3,3]
            l++;
            h--;
            continue;
           }
           else if(v[mid]>v[h] || v[mid]>v[l])//left array sorted till mid
           { if(target >= v[l] && target < v[mid]) //checks for target in left sorted part
                  h=mid-1;
             else
                  l=mid+1;  
           }
           else if(v[mid]<v[h] || v[mid]<v[l])//Right array sorted from mid
           { if(target >= v[mid] && target <= v[h]) //Checks for Target in Right sorted part
                    l=mid+1;
             else
                    h=mid-1;
           } 
        }
        return false;
    }
