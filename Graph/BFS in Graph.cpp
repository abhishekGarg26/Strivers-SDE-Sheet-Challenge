//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Approach-1 (When adjacency list is given)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
                }
            
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// Approach-2 (When Edges are given)

void BFS(int start,int vis[],vector<int> &ans,vector<int> adj[]){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                    }
                }
            
        }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
        vector<int> ans;
        if(vertex==0) return ans;
        vector<int> adj[vertex];
        for(auto it: edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        for(int i=0;i<vertex;i++){ // for getting answer in sorted order this can also be ignored
            sort(adj[i].begin(),adj[i].end());
        }
        int vis[vertex]={0};
        for(int i=0;i<vertex;i++){
            if(!vis[i]){
                vis[i]=1;
                BFS(i,vis,ans,adj);
            }
        }
        return ans;
        
}