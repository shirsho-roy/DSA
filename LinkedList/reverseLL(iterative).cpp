#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        if(head==NULL) return head;
        ListNode* p=NULL;
        ListNode* n=head->next;  
        while(curr){
            curr->next=p; //Reversing next nodes
            p=curr;
            curr=n;
            if(n) n=n->next;
        }
         return p;
    }
};

//Reverse by recursion
 struct ListNode* reverse(struct ListNode *head){
        //Hypothesis returns head of reversed lL
        
        //Base
        if(head->next==NULL){
            return head;
        }
        struct ListNode* revHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return revHead;
    }
    struct ListNode* reverseList(struct ListNode *head)
    {
        return reverse(head);
    }