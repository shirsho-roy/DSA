#include<bits/stdc++.h>
using namespace std;

class Solution {
    int path;

    public int diameter(Node* root) {
        path = 1;
        depthFirstSearch(root);
        return path - 1;
    }

    public:
    //For n-ary tree : Find max diameter of any 2 subtree with max depth
    //As diameter is leftheight+rightheight+1
    int depthFirstSearch(Node* node) {
        if (node == NULL)
            return 0;   
        int maxDepth1 = 0, maxDepth2 = 0;
        List<Node> children = node.children;  
        for (Node child : children) {
            int curDepth = depthFirstSearch(child);
            if (curDepth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = curDepth;
            } else if (curDepth > maxDepth2)
                maxDepth2 = curDepth;
            path = Math.max(path, maxDepth1 + maxDepth2 + 1);
        }
        return maxDepth1 + 1;
    }

    public:
    //For Binary tree
     int depthFirstSearch(TreeNode* node) {
        if (node == NULL)
            return 0;
        int leftDepth = depthFirstSearch(node.left);
        int rightDepth = depthFirstSearch(node.right);
        path = max(path, leftDepth + rightDepth + 1);
        return max(leftDepth, rightDepth) + 1;
    }
}