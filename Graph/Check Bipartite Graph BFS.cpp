#include <bits/stdc++.h>
using namespace std;

bool bfs(int node,int color[],vector<int> adj[]){
	color[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int parent=q.front();
		q.pop();
		for(auto it: adj[parent]){
			// If the adjacent node is not colored you will give the opposite color of the node
			if(color[it]==-1){
				color[it]=!color[parent];
				q.push(it);
			}
			// If the adjacent guy has same color someone did color it on some other path
			else if(color[it]==color[parent]) return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int V=edges.size();
	vector<int> adj[V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int color[V];
	for(int i=0;i<V;i++) color[i]=-1;
	for(int i=0;i<V;i++){
		if(color[i]==-1){
			if(bfs(i,color,adj)==false) return false;
		}
	}
	return true;
}