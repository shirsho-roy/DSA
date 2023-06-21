#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

   int getDecimalValue(ListNode* head){
      ListNode *p=head;
      int s=0;
      while(p){
        s=s*2+1*p->val;
        p=p->next;
      }
      return s;
   }