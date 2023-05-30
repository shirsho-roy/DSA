#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Space Optimized
    int tribonacci(int n) {
        int a=0;
        int b=1;
        int c=1;
        if(n==0) return n;
        if(n==1 || n==2) return 1;
        for(int i=3;i<=n;i++){
            long long int curr=a+b+c;
            a=b;
            b=c;
            c=curr;
        }
        return c;
    }
};