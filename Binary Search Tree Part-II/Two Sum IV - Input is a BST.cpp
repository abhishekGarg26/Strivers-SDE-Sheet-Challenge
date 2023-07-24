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

// Approach-1 (Using extra memory)

class Solution {
public:
    void inorder(TreeNode* root,unordered_map<int,TreeNode*> &mp){
        if(root==NULL) return;
        inorder(root->left,mp);
        mp[root->val]=root;
        inorder(root->right,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,TreeNode*> mp;
        inorder(root,mp);
        for(auto it:mp){
            int rem=k-it .first;
            if(mp.find(rem)!=mp.end() && mp[rem]!=it.second) return true;
        }
        return false;

    }
};

// Approach-2 (Using BSTIterator)

class BSTIterator{
    private:
        stack<TreeNode*> st;
        bool reverse; //true->before, false->next
        void pushAll(TreeNode* node){
            for(;node!=NULL;){
                st.push(node);
                if(!reverse){
                    node=node->left;
                }else{
                    node=node->right;                    }
            }
        }
    public:
        BSTIterator(TreeNode*root, bool isReverse){
            reverse=isReverse;
            pushAll(root);
        }
        int next(){
            TreeNode* node=st.top();
            st.pop();
            if(!reverse) pushAll(node->right);
            else pushAll(node->left);
            return node->val;
        }
        bool hasNext(){
            return !st.empty();
        }

};
class Solution {
public:
   
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j < k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};