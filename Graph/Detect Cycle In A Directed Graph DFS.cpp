#include <bits/stdc++.h>
using namespace std;

// Approach -1 (Using Two Arrays vis & pathVis)

bool dfs(int node,int vis[],int pathVis[],vector<int> adj[]){
  vis[node]=1;
  pathVis[node]=1;
    // visit adjacent nodes
  for(auto adjacentNode: adj[node]){
    // when the node is not visited
    if(!vis[adjacentNode]){
      if(dfs(adjacentNode,vis,pathVis,adj)==true) return true;
    }
    // If the node has been previously visited but it has been visited in the same path
    else if(pathVis[adjacentNode]){
      return true;
    }
  }
  pathVis[node]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n+1];
    for(auto it: edges){
        adj[it.first].push_back(it.second);
    }
    int vis[n+1]={0};
    int pathVis[n+1]={0};
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            if(dfs(i,vis,pathVis,adj)==true){
                return 1;
            }
        }
    }
    return 0;
}

// Approach -2 (Using only single vis array)

// Is it is visited in path then it is marked as 1 otherwise if returns false 
// then mark it 2 so that we will not check it again in some other path & directly return false.

bool dfs(int node,int vis[],vector<int> adj[]){
  vis[node]=1;
  for(auto adjacentNode: adj[node]){
    if(!vis[adjacentNode]){
      if(dfs(adjacentNode,vis,adj)==true) return true;
    }else if(vis[adjacentNode]==1){
      return true;
    }
  }
  vis[node]=2;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[n+1];
    for(auto it: edges){
        adj[it.first].push_back(it.second);
    }
    int vis[n+1]={0};
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            if(dfs(i,vis,adj)==true){
                return 1;
            }
        }
    }
    return 0;
}