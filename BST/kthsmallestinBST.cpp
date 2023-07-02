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
    int cnt=0;
    int v;
    //Inorder traversal :Count at point of node visit
    void dfs(TreeNode* root,int k){
       if(root==NULL) return ;
       
       dfs(root->left,k);
         if(++cnt==k) v=root->val;
       dfs(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return v;
    }
};