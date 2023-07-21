#include <bits/stdc++.h> 

using namespace std;

 template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    bool findPath(TreeNode<int>* root,TreeNode<int>* leaf,stack<TreeNode<int>*> &st){
    if(!root) return false; 
    st.push(root);
    if(root->data==leaf->data) return true;
     bool left=findPath(root->left,leaf,st);
     if(left) return true;
     bool right=findPath(root->right,leaf,st);
     if(right) return true;
     st.pop();
     return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(!root) return NULL;
    stack<TreeNode<int>*> st;
    findPath(root,leaf,st);
    TreeNode<int>* newRoot=st.top();
    st.pop();
    TreeNode<int>* parent=newRoot;
    while(!st.empty()){
        TreeNode<int>* cur=st.top();
        st.pop();
        if(cur->left==parent){
            cur->left=NULL;
        }else{
            cur->right=cur->left;
            cur->left=NULL;
        }
        parent->left=cur;
        parent=parent->left;
    }
    return newRoot;
    
}