#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head==NULL || head->next==NULL) return false;
        ListNode *f=head;
        ListNode *s=head;
        int c=0;
        
        while(f!=NULL && f->next!=NULL){
            if(f==s) c++;
            if(c>1) return true;
            s=s->next;
            f=f->next;
            if(f!=NULL ) f=f->next;
        }
        return false;
    }


    //First Index of a cycle in LL  (Also this method can be used to detect cycle in LL)
     ListNode *detectCycle(ListNode *head) {
         map<ListNode*,int> m;
         if(head==NULL || head->next==NULL) return NULL;
         ListNode *p=head;
         while(p!=NULL){
             if(m[p]==1) return p;
             m[p]=1;
             p=p->next;
         }
         return NULL;
    }
};