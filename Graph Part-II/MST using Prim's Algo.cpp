#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (When only mstSum is asked for graph consisting of nodes from 0 to N)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        // {wt,node}
        pq.push({0,0});
        int sum=0;
        // ElogE + ElogE
        while(!pq.empty()){
            // logE
            auto it=pq.top();
            int edgeWt=it.first;
            int node=it.second;
            pq.pop();
            if(vis[node]==1) continue;
            // add it to the mst
            vis[node]=1;
            sum+=edgeWt;
            // ElogE
            for(auto it:adj[node]){
                int adjNode=it[0];
                int wt=it[1];
                if(!vis[adjNode]){
                    pq.push({wt,adjNode});
                }
            }
        }
        return sum;
    }

// Approach-2 {Finding both mstSum and MST edges with weights}    
// Priority Queue storing {weight,{node,parent}} where nodes = 1 to N
vector<pair<pair<int, int>, int>> calculatePrimsMST(int V, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
        vector<vector<int>> adj[V+1];
        for(auto it:g){
            int u=it.first.first;
            int v=it.first.second;
            int wt=it.second;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{1,-1}});
        int sum=0;
        // MST storing {{parent,node},weight}
        vector<pair<pair<int,int>,int>> mst;
        vector<int> vis(V+1,0);
        while(!pq.empty()){
            auto it=pq.top();
            int wt=it.first;
            int node=it.second.first;
            int parent=it.second.second;
            pq.pop();
            if(vis[node]==1) continue;
            if(parent!=-1){
                mst.push_back({{parent,node},wt});
            }
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode]){
                    pq.push({edW,{adjNode,node}});
                }
            }
        }
        return mst;
}
