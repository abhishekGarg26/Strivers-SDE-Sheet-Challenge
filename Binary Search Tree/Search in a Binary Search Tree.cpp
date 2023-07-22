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

// Recursive Approach

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val== val) return root;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(root->val > val) left = searchBST(root->left,val);
        else right = searchBST(root->right,val);
        return left ? left : right;
    }
};

// Iterative Approach

TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }