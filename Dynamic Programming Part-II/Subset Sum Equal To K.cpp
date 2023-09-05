#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (Using Recursion)

bool f(int ind, int target, vector<int> arr){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    bool notTake= f(ind-1,target,arr);
    bool take = false;
    if(arr[ind]<= target) take = f(ind-1,target-arr[ind],arr);
    return take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1,k,arr);
}

// Approach-2 (Using DP)

bool f(int ind, int target, vector<int> arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake= f(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind]<= target) take = f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

// Approach-3 (Using Tabulation)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int ind=0;ind<n;ind++) dp[ind][0]=true;
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake= dp[ind-1][target];
            bool take = false;
            if(arr[ind]<= target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n-1][k];
}

// Approach-4 (Space Optimization in Tabulation)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,0), cur(k+1,0);
    prev[0] = cur[0] = true;
    if(arr[0]<=k)
        prev[arr[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake= prev[target];
            bool take = false;
            if(arr[ind]<= target) take = prev[target-arr[ind]];
            cur[target] = take | notTake;
        }
        prev=cur;
    }
    return prev[k];
}