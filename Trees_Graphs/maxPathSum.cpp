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

class Solution {
public:
    int mx=INT_MIN;
    int maxsum(TreeNode* root){
        if(root==NULL) return 0;
        int lsum=max(maxsum(root->left),0);
        int rsum=max(maxsum(root->right),0);
        mx=max(mx,(root->val)+lsum+rsum);
        return max({root->val+lsum,root->val+rsum});
    }
    
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return mx;
    }
};