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

//  Approach -1 (TC->O(1) SC->O(N)) 

class BSTIterator {
public:
    TreeNode* cur;
    vector<int> inorder;
    int pointer;
    bool first;
    void in(TreeNode* root,vector<int> &inorder){
        if(!root) return;
        in(root->left,inorder);
        inorder.push_back(root->val);
        in(root->right,inorder);
    }
    BSTIterator(TreeNode* root) {
        cur=root;
        in(root,inorder);
        pointer=0;
        first=true;
    }
    
    int next() {
        if(first) {
            first=false;
            return inorder[pointer];
        }
        return inorder[++pointer];
    }
    
    bool hasNext() {
        if(first) return true;
        if(pointer+1<inorder.size()) return true;
        return false;
    }
};

// Approach-2 (TC->O(1) SC->O(H))

class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node){
        for( ; node!=NULL ; st.push(node), node=node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode=st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};