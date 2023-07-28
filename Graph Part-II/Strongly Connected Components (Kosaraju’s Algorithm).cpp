#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int vis[],vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs3(int node,int vis[],vector<int> adjT[],vector<vector<int>> &ans){
    ans[ans.size()-1].push_back(node);
    vis[node]=1;
    for(auto it: adjT[node]){
        if(!vis[it]){
            dfs3(it,vis,adjT,ans);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
    // O(2*V) space
    int vis[V]={0};
    stack<int> st;
    // O(V+E) time
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    // O(V+E) space
    vector<int> adjT[V];
    // O(V+E) time
    for(int i=0;i<V;i++){
        vis[i]=0;
        for(auto it: adj[i]){
            // i->it
            // it->i
            adjT[it].push_back(i);
        }
    }
    int scc=0;
    vector<vector<int>> ans;
    // O(V+E) time
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            ans.push_back({});
            dfs3(node,vis,adjT,ans);
            
        }
    }
    return ans;
}