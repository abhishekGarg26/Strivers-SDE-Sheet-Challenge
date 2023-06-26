#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// Approach-1 (USING RECURSION)

Node* mergeTwoLists(Node* a,Node*b){
    Node* dummy=new Node(0);
    Node* temp=dummy;
    while(a!=NULL && b!=NULL){
        if(a->data < b->data ){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a) temp->bottom=a;
    else temp->bottom=b;
    return dummy->bottom;
}
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL) return root;
    root->next=flatten(root->next);
    root=mergeTwoLists(root,root->next);
    root->next=NULL;
    return root;
   
}

// Approach-2 (USING EXTRA SPACE)

Node *flatten(Node *root)
{
   vector<int> a;
   for(Node *start=root;start!=NULL;start=start->next){
       for(Node *temp=start;temp!=NULL;temp=temp->bottom){
           a.push_back(temp->data);
       }
   }
   sort(a.begin(),a.end());
   Node *head=NULL,*b=NULL;
   for(auto x:a){
       if(head==NULL){
           head=new Node(x);
           b=head;
       }else{
           Node* t=new Node(x);
           b->bottom=t;
           b=b->bottom;
       }
   }
   return head;
}