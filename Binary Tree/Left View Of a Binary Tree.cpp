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

void traverse(TreeNode<int>* root,vector<int> &ans, int level){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    traverse(root->left,ans,level+1);
    traverse(root->right,ans,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
   vector<int> ans;
   traverse(root,ans,0);
   return ans;
}