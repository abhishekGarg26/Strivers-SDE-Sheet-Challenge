#include <bits/stdc++.h> 

using namespace std;

template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

// Soln - Size of Largest BST in Binary Tree (CodeStudio)

class NodeValue{
    public:
        int minNode,maxNode,maxSize;
        NodeValue(int minNode,int maxNode,int maxSize){
            this->minNode=minNode;
            this->maxNode=maxNode;
            this->maxSize=maxSize;
        }
};
NodeValue maxSizeBSTHelper(TreeNode<int>* root){
    // An empty tree is a BST of size 0
    if(!root) return NodeValue(INT_MAX,INT_MIN,0);
    // Get values from left & right subtree of current tree
    auto left=maxSizeBSTHelper(root->left);
    auto right=maxSizeBSTHelper(root->right);
    // If current node is greater than max in the left & smaller then min in the right, then it is a valid BST
    if(left.maxNode < root->data && root->data < right.minNode){
        // It is a BST
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    }
    // Otherwise return [-inf,inf] so that parent can't be a valid BST
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return maxSizeBSTHelper(root).maxSize;
}

// Soln - Maximum Sum BST in Binary Tree (Leetcode)


class NodeVal{
    public:
        int minNode,maxNode,maxSum;
        NodeVal(int minNode,int maxNode,int maxSum){
            this->minNode=minNode;
            this->maxNode=maxNode;
            this->maxSum=maxSum;
        }
};
class Solution {
private:
    int maxi=0;
    NodeVal maxSumBSTHelper(TreeNode<int>* root){
        if(!root) return NodeVal(INT_MAX,INT_MIN,0);
        auto left=maxSumBSTHelper(root->left);
        auto right=maxSumBSTHelper(root->right);
        if(left.maxNode < root->data && root->data < right.minNode){
            maxi=max(maxi,left.maxSum+right.maxSum+root->data);
            return NodeVal(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSum+right.maxSum+root->data);
        }
        return NodeVal(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
public:
    int maxSumBST(TreeNode<int>* root) {
        maxSumBSTHelper(root).maxSum;
        return maxi;
    }
};