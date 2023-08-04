#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (Using Min-Heap)

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for(int i=0;i<V;i++) dist[i]=1e9;
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int edgeWeight=it[1];
            int adjNode=it[0];
            if(dis+edgeWeight < dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

// Approach-2 (Using Set) 

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        dist[S]=0;
        set<pair<int,int>> st;
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            st.erase(it);
            for(auto it : adj[node]){
                int adjNode=it[0];
                int edgeW=it[1];
                if(dis+edgeW < dist[adjNode]){
                    // erase if it existed
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                    dist[adjNode]=dis+edgeW;
                    st.insert({dist[adjNode],adjNode});
                }
                
            }
        }
        return dist;
        
    }