 #include <bits/stdc++.h> 

using namespace std;

 struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
  };

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
       vector<int> ans;
       if(!root) return ans;
       map<int,int> mp;
       queue<pair<Node*,int>> q;
       q.push({root,0});
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           Node* node=it.first;
           int line=it.second;
           if(mp.find(line)==mp.end())
            mp[line]=node->val;
           if(node->left){
               q.push({node->left,line-1});
           }
           if(node->right){
               q.push({node->right,line+1});
           }
       }
       for(auto it:mp){
           ans.push_back(it.second);
       }
       return ans;
    }

};