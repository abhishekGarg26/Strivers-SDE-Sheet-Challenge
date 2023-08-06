#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (When only positive weights are allowed)

void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
                // -1 represents a node which is not reachable directly
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	   // For detecting negative cycle
	    for(int i=0;i<n;i++){
	        if(matrix[i][i]<0) return;
	    }

	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}

    // Approach-2 (When negative weights are also allowed)

    int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
		vector<vector<int>> matrix(n+1,vector<int>(n+1,1e9));
		for(auto it: edges){
			int u=it[0];
			int v=it[1];
			int wt=it[2];
			matrix[u][v]=wt;

		}
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=n;j++){
                // -1 represents a node which is not reachable directly
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    for(int k=1;k<=n;k++){
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
        // If value of weight go out of given range of weight then no path exists to dest node so return 1e9
		 if(matrix[src][dest]>1e5) return 1e9;
	   
	    return matrix[src][dest];
}