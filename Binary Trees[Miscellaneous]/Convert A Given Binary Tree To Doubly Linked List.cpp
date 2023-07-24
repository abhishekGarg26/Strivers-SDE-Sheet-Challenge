#include <bits/stdc++.h> 
using namespace std;

template<typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

// Approach-1 (Using Morris Inorder Traversal)

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
        BinaryTreeNode<int>* cur=root;
        BinaryTreeNode<int>* newRoot=NULL;
        BinaryTreeNode<int>* backTrack=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                if(!newRoot) newRoot=cur;
                else{
                    backTrack->right=cur;
                    cur->left=backTrack;
                }
                backTrack=cur;
                cur=cur->right;
            }else{
                BinaryTreeNode<int>* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    cur->left=prev;
                    backTrack=cur;
                    cur=cur->right;
                }
            }
        }
        return newRoot;
}