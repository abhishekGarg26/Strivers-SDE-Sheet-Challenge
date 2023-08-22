#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (Using Recursion)
class Solution{
public:
    int f(int i,int j,int arr[]){
        if(i==j) return 0;
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=(arr[i-1]*arr[k]*arr[j]) + f(i,k,arr) + f(k+1,j,arr);
            if(steps < mini) mini=steps;
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return f(1,N-1,arr);
    }
};

// Approach-2 (Using DP)
class Solution{
    public:
    int f(int i,int j,vector<int> arr,vector<vector<int>> &dp){
            if(i==j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=(arr[i-1]*arr[k]*arr[j]) + f(i,k,arr,dp) + f(k+1,j,arr,dp);
                if(steps < mini) mini=steps;
            }
            return dp[i][j]=mini;
        }
    int matrixMultiplication(vector<int> &arr, int N)
    {
        // Write your code here.
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
};

// Approach-3 (Using Tabulation)
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
        int dp[N][N];
        for(int i=1;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                int steps=(arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                if(steps < mini) mini=steps;
            }
            dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
}