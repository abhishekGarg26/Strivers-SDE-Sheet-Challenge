#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent,int vis[],vector<int> adj[]){
    vis[node]=1;
    for(auto adjacentNode:adj[node]){
        if(!vis[adjacentNode]){
            if(dfs(adjacentNode,node,vis,adj)==true) return true;
        }
        else if(parent!=adjacentNode) return true;
    }
    return false;
    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int vis[n+1]={0};
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true){
                return "Yes";
            }
        }
    }
    return "No";
}
