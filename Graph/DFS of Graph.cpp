//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        // DFS when graph is undirected but connected and adjacency list is given
        void dfs(int node,vector<int> adj[],int vis[],vector<int> &ans){
            vis[node]=1;
            ans.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it,adj,vis,ans);
                }
            }
        }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        int start=0;
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Approach-2 (When adj list is not given then prepare adj list and run dfs for each vertex as graph is disconnected) 

void dfs(int node,int vis[],vector<int> &component,vector<int> adj[]){
    vis[node]=1;
    component.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,component,adj);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Prepared adjecency list
    vector<int> adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int vis[V]={0};
    vector<vector<int>> ans;
    // For all nodes call DFS if not visited
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> component;
            dfs(i,vis,component,adj);
            ans.push_back(component);
        }
    }
    return ans;
    
}