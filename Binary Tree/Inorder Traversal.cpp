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
 

// Approach-1 (Recursive)

class Solution {
public:
    void traverse(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        traverse(root,ans);
        return ans;
    }
};

// Approach-2 (Iterative)

vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode* node=root;
        stack<TreeNode*> st;
        vector<int> inorder;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }