#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode *dummyhead=new ListNode(0); //dummyhead
        ListNode *s=dummyhead;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0  ){
          int x=0,y=0;
          if(l1)  x=l1->val;
          if(l2)  y=l2->val;
          sum=x+y+carry;
          carry=sum/10;
          s->next=new ListNode(sum%10);
          s=s->next;
          if(l1) l1=l1->next;
          if(l2) l2=l2->next;
        }
        return dummyhead->next;
    }
};