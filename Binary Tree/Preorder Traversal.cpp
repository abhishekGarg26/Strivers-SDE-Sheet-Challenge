#include <bits/stdc++.h> 

using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// Recursive Approach

class Solution {
public:
    void traverse(TreeNode* root,vector<int> &preorder){
        if(root==NULL) return;
        preorder.push_back(root->val);
        traverse(root->left,preorder);
        traverse(root->right,preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        traverse(root,preorder);
        return preorder;
    }
};

// Iterative Approach

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> preorder;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                preorder.push_back(node->val);
                node=node->left;
            }else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                node=node->right;
            }
        }
        return preorder;
    }
};