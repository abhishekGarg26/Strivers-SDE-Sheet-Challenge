#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src,int vis[],vector<int> adj[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});
            }
            else if(parent!=adjacentNode){
                return true;
            }
        }
    }
    return false;
}

// For 1 based indexing of vertices in graph
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
            if(detectCycle(i,vis,adj)){
                return "Yes";
            }
        }
    }
    return "No";
}
