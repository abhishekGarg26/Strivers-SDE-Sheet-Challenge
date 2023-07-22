#include <bits/stdc++.h> 

using namespace std;
template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

BinaryTreeNode<int>* inorderSuccessor(BinaryTreeNode<int>* root,int key){
        BinaryTreeNode<int>* successor=NULL;
        while(root){
            if(root->data <= key){
                root=root->right;
            }else{
                successor=root;
                root=root->left;
            }
        }
        return successor;
    }
    BinaryTreeNode<int>* inorderPredecessor(BinaryTreeNode<int>* root,int key){
        BinaryTreeNode<int>* predecessor = NULL;
        while(root){
            if(root->data >= key){
                root=root->left;
            }else{
                predecessor=root;
                root=root->right;
            }
        }
        return predecessor;
    }
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
        BinaryTreeNode<int>* suc=inorderSuccessor(root,key);
        BinaryTreeNode<int>* pre=inorderPredecessor(root,key);
        return {pre ? pre->data : -1, suc ? suc->data : -1};
}
