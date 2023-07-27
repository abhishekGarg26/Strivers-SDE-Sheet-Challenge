#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int indegree[V];
        for(int i=0;i<V;i++) indegree[i]=0;
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
            // Node is in ans so please remove it from adjacent node's indegree
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    
	    return ans.size()==V;
    }
};