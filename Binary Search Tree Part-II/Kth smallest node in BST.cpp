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

// Approach-1 (Using simple inorder traversal)

 int inorder(TreeNode* root,int &cnt,int k){
        if(!root) return 0;
        int left= inorder(root->left,cnt,k);
        cnt++;
        if(cnt==k) return root->val;
        int right= inorder(root->right,cnt,k);
        return left ? left : right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return inorder(root,cnt,k);
    }

// Approach-2 (Using Morris Inorder Traversal)

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