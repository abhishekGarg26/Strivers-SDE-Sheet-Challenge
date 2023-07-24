#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Approach-1 (Using extra space) (TC->O(n) , SC->O(n))

class Solution
{
    public:
    void inorder(Node* root,vector<int> &a){
        if(!root) return;
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> a;
        inorder(root,a);
        return a[a.size()-K];
    }
};

// Approach-2 ( Using reverse inorder traversal )(TC->O(min(n-k,n)) ,  SC->O(min(n-k,n)))
class Solution
{
    public:
     int reverseInorder(Node* root,int &k){
        if(!root) return 0;
        int right= reverseInorder(root->right,k);
        if(root->left || root->right || (!root->left && !root->right)) k--;
        if(k==0) return root->data;
        int left= reverseInorder(root->left,k);
        return right ? right : left;
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        return reverseInorder(root,k);

    }
};

// Approach-3 (Using Morris Traversal) (TC->O(n) , SC->O(1))
class Solution
{
    public:
    int morrisInorder(Node* root,int k,bool flag){
        Node* cur=root;
        int cnt=0;
        int ans=-1;
        while(cur!=NULL){
            if(cur->left==NULL){
                cnt++;
                if(cnt==k) ans=cur->data;
                cur=cur->right;
            }else{
                Node* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k) ans=cur->data;
                    cur=cur->right;
                }
            }
        }
        return flag ? ans : cnt;
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        bool flag=false;
        int n=morrisInorder(root,K,flag);
        K=n-K+1;
        flag=true;
        return morrisInorder(root,K,flag);

    }
};