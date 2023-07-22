#include <bits/stdc++.h> 

using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution
{
    public:
    Node* inorderSuccessor(Node* root,int key){
        if(!root) return NULL;
        Node* cur=root;
        Node* successor=NULL;
        while(cur){
            if(cur->key <= key){
                cur=cur->right;
            }else{
                successor=cur;
                cur=cur->left;
            }
        }
        return successor;
    }
    Node* inorderPredecessor(Node* root,int key){
        if(!root) return NULL;
        Node* cur=root;
        Node* predecessor = NULL;
        while(cur){
            if(cur->key >= key){
                cur=cur->left;
            }else{
                predecessor=cur;
                cur=cur->right;
            }
        }
        return predecessor;
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        suc=inorderSuccessor(root,key);
        pre=inorderPredecessor(root,key);
        return;

    }
};