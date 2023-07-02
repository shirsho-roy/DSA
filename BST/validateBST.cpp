#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
    bool check(TreeNode* root,TreeNode* mn,TreeNode* mx){
        if(root==NULL) return true;
        if(mx && root->val>=mx->val || mn && root->val<=mn->val) return false;
        bool lsubtree=check(root->left,mn,root);
        bool rsubtree=check(root->right,root,mx);
        return lsubtree && rsubtree;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
};