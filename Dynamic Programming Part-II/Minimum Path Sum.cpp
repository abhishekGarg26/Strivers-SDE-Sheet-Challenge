#include <bits/stdc++.h> 
using namespace std;

int minSumPath(vector<vector<int>> &matrix) {
    // Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
}