#include<bits/stdc++.h> 
using namespace std; 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {  //For head not given
        ListNode *temp=node->next;
        swap(node->val,temp->val);
        node->next=temp->next;
        delete(temp);//To prevent Memory leakage
    }
};