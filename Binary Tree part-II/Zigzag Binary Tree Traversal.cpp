#include <bits/stdc++.h> 

using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode<int>*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode<int>* node=q.front();
                q.pop();
                // find position to fill node's value
                int index= leftToRight ? i : size-1-i;
                row[index]=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } 
            // after this level change leftToRight
            leftToRight=!leftToRight;             
            ans.insert(ans.end(),row.begin(),row.end());

        }
        return ans;
}