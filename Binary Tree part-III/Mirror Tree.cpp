#include <bits/stdc++.h> 

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 
void mirror(Node* root) {
        // code here
        if(!root->left && !root->right) return; 
        if(root->left) mirror(root->left);
        if(root->right) mirror(root->right);
        swap(root->left,root->right);
    }