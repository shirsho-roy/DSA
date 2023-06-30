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
    vector<int> preorder(Node* root) {
        
        vector<int> res;
        if(root==NULL) return res;
        Preorder(root,res);
        return res;
    }
    void Preorder(Node *root,vector<int> &res){
        res.push_back(root->val);
        if(root->children.empty()) return;
        for(auto it:root->children){
            Preorder(it,res);
        }
        return;
    }
};