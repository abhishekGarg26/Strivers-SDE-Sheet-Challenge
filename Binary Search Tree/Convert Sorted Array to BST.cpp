#include <bits/stdc++.h> 

using namespace std;

 template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

// Approach - 1 (Recursive)

TreeNode<int>* recursion(vector<int> nums,int start,int end){
        if(start > end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode<int>* newNode=new TreeNode<int>(nums[mid]);
        newNode->left=recursion(nums,start,mid-1);
        newNode->right=recursion(nums,mid+1,end);
        return newNode;
    }
TreeNode<int>* sortedArrToBST(vector<int> &nums, int n)
{
    // Write your code here.
    return recursion(nums,0,n-1);

}

// Approach-2 (Iterative using stack)

/*
    Time Complexity: O(N)
    Space Complexity: O(log(N))

    where 'N' is the total number of elements in the given array.
*/

// NodeData struct to store root node of subtree and their respective range in given array.
struct nodeData
{
    TreeNode<int> *node;

    // Low and high are left and right range for given 'arr'.
    int low, high;

    nodeData(TreeNode<int>* root, int left, int right)
    {
        node = root;
        low = left ;
        high = right;
    }
};


TreeNode<int>* sortedArrToBST (vector<int> &arr, int n)
{
    /*
        Initialise a root node with 'val' = -1 and range [ 0:n-1 ] and push it into a stack data structure.
        Later on we will update its 'val' to arr['mid'], where 'mid' is middle index of range [0:n-1].
    */
    TreeNode<int>* root = new TreeNode<int> (-1);
    stack<nodeData> st;

    nodeData node = nodeData(root, 0, n - 1);
    st.push(node); 

    while (st.empty() == false)
    {
        nodeData curNode = st.top();
        st.pop();

        // Find 'mid' for the currNode and update node with arr[mid].
        int mid = curNode.low + (curNode.high - curNode.low) / 2;
        curNode.node -> val = arr[mid];

        // Push the left part of array, that makes left subtree of current node.
        if (curNode.low < mid)
        {
            curNode.node -> left = new TreeNode<int>(-1);

            node = nodeData(curNode.node -> left, curNode.low, mid - 1);
            st.push(node);
        }

        // Push the right part of array, that makes right subtree of current node.
        if (curNode.high > mid) 
        {
            curNode.node -> right = new TreeNode<int>(-1);
            
            node = nodeData(curNode.node -> right, mid+1, curNode.high);
            st.push(node);
        }
    }

    // Return root of tree.
    return root;
}
