#include<bits/stdc++.h> 
using namespace std; 
 
 //Lower Bound: Smallest index such that arr[ind]>=key
int lowrbound(int arr[],int n,int k){
    int l=0;
    int u=n-1;

    int res=n;
    while(l<=u){
        int mid=l+ (u-l)/2;

        if(arr[mid]>=k){
            res=mid;
            u=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

//Upper Bound: Smallest index such that arr[ind]>key

int upprbound(int arr[],int n,int k){
    int l=0;
    int u=n-1;

    int res=n;
    while(l<=u){
        int mid=l+ (u-l)/2;

        if(arr[mid]>k){
            res=mid;
            u=mid-1;
        }
        else l=mid+1;
    }
    return res;
}