#include <bits/stdc++.h> 

using namespace std;

template <typename T>
class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

// Program to maintain child property

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(root->data <= child) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}  

// Program to check child property

bool isParentSum(BinaryTreeNode < int > *root){
    // Write your code here.
    if(!root) return true;
    bool left=isParentSum(root->left);
    if(!left) return false;
    bool right=isParentSum(root->right);
    if(!right) return false;
    if(root->left || root->right){
        int sum=0;
        if(root->left) sum+=root->left->data;
        if(root->right) sum+=root->right->data;
        return root->data==sum;
    }
    return true;
}