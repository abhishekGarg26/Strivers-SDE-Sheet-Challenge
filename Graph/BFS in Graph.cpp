#include <bits/stdc++.h> 

using namespace std;

#include <bits/stdc++.h> 
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