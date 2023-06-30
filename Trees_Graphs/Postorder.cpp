#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> postorder(Node* root) {
         vector<int> res;
        if(root==NULL) return res;
        Postorder(root,res);
        return res;
    }
    void Postorder(Node *root,vector<int> &res){
       
         if(root->children.empty()) { 
             res.push_back(root->val);
             return;
         }
        for(auto it:root->children){
            Postorder(it,res);
        }
         res.push_back(root->val);
        return;
    }
};