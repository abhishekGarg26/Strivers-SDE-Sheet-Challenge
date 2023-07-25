#include <bits/stdc++.h> 

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*> &mp){
        vector<Node*> neighbor;
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto it: node->neighbors){
            if(mp.find(it)!=mp.end()){
                neighbor.push_back(mp[it]);
            }else{
                neighbor.push_back(dfs(it,mp));
            }
        }
        clone->neighbors=neighbor;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        if(node->neighbors.size()==0){
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};