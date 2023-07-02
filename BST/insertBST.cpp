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
  //Recursive
   TreeNode* insert(TreeNode* root,TreeNode* nd){
       if (root==NULL) return nd;
        else{
            if(nd->val<root->val) root->left=insert(root->left,nd);
            else root->right=insert(root->right,nd);
            return root;
        } 

    }
    //iterative
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nd=new TreeNode(val);
        // return insert(root,nd);
        TreeNode* t=NULL;
        TreeNode* p=root;
        while(p!=NULL){
            t=p;
            if(val<p->val){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(val<t->val) t->left=nd;
        else t->right=nd;
        return root;
    }
};