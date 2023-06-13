#include<bits/stdc++.h> 
using namespace std; 

int firstoccurence(int arr[],int n,int k){
    int res=-1;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==k) {
            res=mid;
            e=mid-1;//Now check before this occurence for 1st occurence
        }
        else if(arr[mid]<k) s=mid+1;
        else e=mid-1;
    }
   return res;
}

int lastoccurence(int arr[],int n,int k){
    int res=-1;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==k) {
            res=mid;
            s=mid+1;//Now check after this occurence for last occurence
        }
        else if(arr[mid]<k) s=mid+1;
        else e=mid-1;
    }
   return res;
}