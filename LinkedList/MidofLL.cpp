#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    int count(ListNode* p){
        int c=0;
        while(p!=NULL){
          c++;
          p=p->next;
        }
        return c;
    }
    ListNode* middleNode(ListNode* head) {
        int n=count(head);
        ListNode *x;
        for(int i=1;i<=n/2;i++){
            head=head->next;
        }
        x=head;
        return x;
    }
   //Fast and Slow Pointer approach
    ListNode* midNode(ListNode* head){
        ListNode *fast,*slow;
        fast=head;
        slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=(fast->next);
            if(fast!=NULL) fast=fast->next; 
            slow=slow->next;
        }
        return slow;
    }
};