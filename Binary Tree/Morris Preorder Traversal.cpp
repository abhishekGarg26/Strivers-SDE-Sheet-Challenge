#include <bits/stdc++.h> 

using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
        TreeNode* cur=root;
        vector<int> inorder;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->data);
                cur=cur->right;
            }else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    inorder.push_back(cur->data);
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
            return inorder;
}