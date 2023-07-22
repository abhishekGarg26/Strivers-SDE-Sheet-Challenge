#include <bits/stdc++.h> 

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Approach-1 (Using Stack) 

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node* prev=NULL;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(prev) prev->next=node;
                prev=node;
            }

        }
        return root;

        
    }
};

// Approach-2 Using Queue

Node* connect(Node* root) {
        if(!root) return root;
        Node* cur=root;
        while(cur->left!=NULL){
            Node* temp=cur;
            while(cur!=NULL){
                cur->left->next=cur->right;
                cur->right->next = cur->next==NULL ? NULL : cur->next->left;
                cur=cur->next;
            }
            cur=temp->left;
        }
        return root;
        
    }