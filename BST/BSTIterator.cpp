#include <bits/stdc++.h>
using namespace std;

 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        if(top->right){
            TreeNode* right=top->right;
            while(right){
                st.push(right);
                right=right->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        else return true;
    }
};
