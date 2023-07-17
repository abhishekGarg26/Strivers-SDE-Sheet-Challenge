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
        vector<int> preorder;
        if(root==NULL) return preorder;
        stack<TreeNode*> st;
        TreeNode* node;
        st.push(root);
        while(!st.empty()){
            node=st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }
        return preorder;
    }
};