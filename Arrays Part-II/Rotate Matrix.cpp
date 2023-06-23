#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // TC-> O(N/2 * N/2)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // TC-> O(N*N/2)
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};