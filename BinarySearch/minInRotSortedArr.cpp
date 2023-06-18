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
         
         else if(v[mid]>v[h]){ //Left Sorted: pivot is mid or to right
           l=mid+1;
         }
         else if(v[mid]<=v[h]){ //right sorted :Pivot can be mid or to left
           h=mid;
         }
    }
    return v[h];
}