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

// Approach -1 (Using sorting)

class Solution {
public:
   TreeNode* buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};

// Approach-2 (Using Recursion)

class Solution {
public:
    TreeNode* build(vector<int> preorder,int& i,int bound){
      if(i==preorder.size() || preorder[i] > bound) return NULL;
      TreeNode* root=new TreeNode(preorder[i++]);
      root->left=build(preorder,i,root->val);
      root->right=build(preorder,i,bound);
      return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};