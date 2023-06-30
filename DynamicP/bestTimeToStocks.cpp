#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size());
        int buy=prices[0];
        profit[0]=prices[0];
        for(int i=1;i<prices.size();i++){
           buy=min(buy,prices[i]); //stores min price upto  ith index
           int sell=prices[i];//selling price at that index
           profit[i]=sell-buy;
        }
        return *max_element(profit.begin(),profit.end());
    }
};