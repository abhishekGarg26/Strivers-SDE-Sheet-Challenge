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

//  Approach-1 

class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

// Approach-2

void flatten(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur=st.top(); st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        if(!st.empty()) cur->right=st.top();
        cur->left=NULL;
    }
}

// Approach-3

void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left){
                TreeNode* prev=cur->left;
                while(prev->right) prev=prev->right;
                prev->right=cur->right;
                cur->right=cur->left;
            }
            cur->left=NULL;
            cur=cur->right;
        }
    }