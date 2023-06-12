#include<bits/stdc++.h> 
using namespace std; 
 int orderagnosticSearch(vector<int> a,int k){
    if(a.size()==1){
        if(a[0]==k) return a[0];
        else return -1;
    }
    else{
    if(a[0]<a[1]){//Ascending
      int l=0,h=a.size()-1;
      while(l<=h){
       int mid=l+(h-l)/2;
       if(a[mid]==k) return a[mid];
       else if(a[mid]<k) l=mid+1;
       else h=mid-1;
      }
      return -1;
    }
    else{
       int l=0,h=a.size()-1;
      while(l<=h){//Descending
       int mid=l+(h-l)/2;
       if(a[mid]==k) return a[mid];
       else if(a[mid]>k) l=mid+1;
       else h=mid-1;
      }
      return -1;  
    }
    }
 }