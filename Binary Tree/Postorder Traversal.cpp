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
    void traverse(TreeNode* root,vector<int> & postorder){
        if(root==NULL) return;
        traverse(root->left,postorder);
        traverse(root->right,postorder);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        traverse(root,postorder);
        return postorder;
    }
};

// Iterative Approach using Two Stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* node=root;
        s1.push(node);
        while(!s1.empty()){
            node=s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()) postorder.push_back(s2.top()->val), s2.pop();
        return postorder;
    }
};

// Iterative Approach Using Single Stack

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top(), st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==(st.top()->right)){
                        temp=st.top(), st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return postorder;
    }