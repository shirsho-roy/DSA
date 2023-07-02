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
    TreeNode* findInorderSuccesor(TreeNode* nd,int key){
        TreeNode* p=nd;
        if(p==NULL ) return NULL;
        if(p->right!=NULL)
        {  p=p->right;
        while(p->left!=NULL){
           p=p->left;
        }
        return p;}
        else return NULL;
    }
    //Iterative-NOT Intitive
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL && key==root->val) return NULL;
        TreeNode* t=NULL;
        TreeNode* q=NULL;
        TreeNode* r=root;
        
        while(r!=NULL){
            if(r->val==key){
            q=r;
            TreeNode *z=findInorderSuccesor(q,key);
            if(z){
                swap(r->val,z->val);
                r=z;
            }
            else{ t=r->left;
             r=NULL;
            }
            }
            else if(key<r->val) {
             
             r=r->left;}
            else{
               
                 r=r->right;
            }
        }
        delete(q);
         if(t) return t;
         else return root;
       
    }

    //Recursive
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
         
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
       
    }
};