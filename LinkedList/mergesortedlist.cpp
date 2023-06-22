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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p=list1;
        ListNode *q=list2;
        if(p == NULL)
        {
			return q;
		}
		else if(q == NULL)
        {
			return p;
		} 
		else if(p->val<=q-> val){
        
			p -> next = mergeTwoLists(p -> next, q);
			return p;
		}
		else
        {
			q -> next = mergeTwoLists(p, q->next);
			return q;            
		}
            
        }
    
    //also can merge using 3rd ll
};