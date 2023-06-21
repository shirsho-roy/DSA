#include <bits/stdc++.h>
using namespace std;


//Search for pivot first
//Minimum element is the min pivot in rotated Sorted array
int pivotsearch(vector<int> &v){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
         if(l==h) return v[l];
         
         else if(v[mid]>v[h]){ //Left Sorted: pivot is  to right
           l=mid+1;
         }
         else if(v[mid]<=v[h]){ //right sorted :Pivot can be mid or to left
           h=mid;
         }
    }
    return v[h];
}


//also for how many times array has been rotated return the pivot index


//Minimum in Rotated Sorted Array with duplicate elements
 int findMin(vector<int>& v) {  //** LC Hard
         int l=0;
       int h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
         if(l==h) return v[l];
          if(v[mid]==v[l] && v[mid]==v[h]){  // Additional condition for [3,4,5,3,3,3,3]
            l++;
            h--;
            continue;
           }
         else if(v[mid]>v[h]){ //Left Sorted: pivot is mid or to right
           l=mid+1;
         }
         else if(v[mid]<=v[h]){ //right sorted :Pivot can be mid or to left
           h=mid;
         }
    }
    return v[h];
    }