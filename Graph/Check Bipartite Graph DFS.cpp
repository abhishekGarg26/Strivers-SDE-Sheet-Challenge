#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,int col,int color[],vector<int> adj[]){
	color[node]=col;
	for(auto it: adj[node]){
		if(color[it]==-1){
			if(dfs(it,!col,color,adj)==false) return false;
		}
		else if(color[it]==col) return false;
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
			if(dfs(i,0,color,adj)==false) return false;
		}
	}
	return true;
}