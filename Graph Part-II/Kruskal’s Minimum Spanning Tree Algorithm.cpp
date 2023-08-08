#include <bits/stdc++.h> 
using namespace std;
class DisjointSet{
    // space -> O(V)+O(V)
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   // Since graph is bidirectional so two edges will be stored for a single edge
        // but disjointSet will discard another one as ultimate parent of two will already 
        // become same when first passed to union by size.
        // 1 -> 2 wt=5
        // 2 -> 1 wt=5
        // adj[1] -> (2,5)
        // adj[2] -> (1,5)
        // edges-> 5 1 2 , 5 2 1
        // space -> O(M) [M=2*E]
        vector<pair<int,pair<int,int>>> edges;
        // time -> O(V+M)
        for(int i=0;i<V;i++){
            int node=i;
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                edges.push_back({wt,{node,adjNode}});
            }
        }
        // time-> O(MlogM)
        sort(edges.begin(),edges.end());
        int mstWt=0;
        // space->O(2V)
        DisjointSet ds(V);
        // space -> O(E)
        vector<vector<int>> mst;
        // time -> O(M x 4 x alpha x 2)
        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=wt;
                // We can store mst nodes here
                mst.push_back({u,v});
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};