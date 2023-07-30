#include <bits/stdc++.h> 
using namespace std;

int floydWarshall(int V, int m, int S, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(V+1, 1e9);
		dist[S] = 0;
		for (int i = 1; i <= V ; i++) {
			for (int j=0;j<m;j++) {
				int u = edges[j][0];
				int v = edges[j][1];
				int wt = edges[j][2];
				if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
        bool flag=0;
		// Nth relaxation to check negative cycle
		for (int j=0;j<m;j++) {
			int u = edges[j][0];
			int v = edges[j][1];
			int wt = edges[j][2];
			if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
				flag=1;
			}
		}
        if(flag==0) return dist[dest];

		return -1;
}