#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode* rotate(ListNode* head){
        ListNode* p=head;
        ListNode *t=NULL;
        while(p->next!=NULL){
            t=p;
            p=p->next;
        }
       p->next=head;
       head=p;
       t->next=NULL;
       return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int cnt=0;
        ListNode* q=head;
        while(q!=NULL){
            cnt++;
            q=q->next;
        }
        int rot=k%(cnt);
        while(rot--){
            head=rotate(head);
        }
        return head;
    }
};