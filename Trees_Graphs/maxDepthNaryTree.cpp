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
    int maxDepth(Node* root) {
        if(root==NULL) return 0;   //null children of leaf nodes never reached this for []
        int depth=0;//shud have been base case for leaf node itself
        if(root->children.empty()) return 1;//base case for leaf node
        for(int i=0;i<root->children.size();i++){
            int temph=1+maxDepth(root->children[i]);
            depth=max(depth,temph);
        }
        return depth;
    }
};