#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        ListNode *temp1=head;
        ListNode *x, *q;
        vector<int> st; //Like Monotonic Stack
        st.push_back(temp1->val);
        temp1=temp1->next;
        while(temp1 != NULL){
            while(!st.empty() && st.back()<temp1->val){
                st.pop_back();
            }
            st.push_back(temp1->val);
            temp1 = temp1->next;
        }
        q=head;
         x=head;
       for(auto &it:st){
           x->val=it;
           q=x;
           x=x->next;
       }
       q->next=NULL;
       return head;
    }
};