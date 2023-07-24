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

// Approach-1 (Using extra space) (TC->O(n) , SC->O(n))

class Solution {
public:
    void inorder(TreeNode* root,vector<int> &a){
        if(!root) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);
        return a[k-1];
    }
};

// Approach-2 (Using simple inorder traversal) (TC->O(min(k,n)) ,  SC->O(min(k,n)))

 class Solution {
public:
     int inorder(TreeNode* root,int &k){
        if(!root) return 0;
        int left= inorder(root->left,k);
        if(root->left || root->right || (!root->left && !root->right)) k--;
        if(k==0) return root->val;
        int right= inorder(root->right,k);
        return left ? left : right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return inorder(root,k);
    }
};

// Approach-3 (Using Morris Inorder Traversal) (TC->O(n) , SC->O(1))

class Solution {
public:
     int morrisInorder(TreeNode* root,int k){
        TreeNode* cur=root;
        int cnt=0;
        int ans=-1;
        while(cur!=NULL){
            if(cur->left==NULL){
                cnt++;
                if(cnt==k) ans=cur->val;
                cur=cur->right;
            }else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k) ans=cur->val;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        return morrisInorder(root,k);
    }
};