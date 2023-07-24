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
NodeValue maxSumBSTHelp(TreeNode<int>* root){
    if(!root) return NodeValue(INT_MAX,INT_MIN,0);
    auto left=maxSumBSTHelp(root->left);
    auto right=maxSumBSTHelp(root->right);
    if(left.maxNode < root->data && root->data < right.minNode){
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return maxSumBSTHelp(root).maxSize;
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