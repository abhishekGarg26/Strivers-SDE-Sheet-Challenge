#include <bits/stdc++.h> 
using namespace std;

int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[V+1];
    for(auto it: edges){
        adj[it.first].push_back(it.second);
    }
    int indegree[V+1]={0};
      for(int i=1;i<V+1;i++){
          for(auto it:adj[i]){
              indegree[it]++;
          }
      }
    queue<int> q;
    for(int i=1;i<V+1;i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    
    if(cnt==V) return false;
    return true;
}