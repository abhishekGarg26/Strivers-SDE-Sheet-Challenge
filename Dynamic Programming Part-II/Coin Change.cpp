#include <bits/stdc++.h>
using namespace std;

// Que 1 -> Coin Change

// Approach-1 (Using Recursion)
class Solution {
public:
    int f(int ind,int T, vector<int> &coins){
        if(ind==0){
            if((T % coins[0]) == 0) return T/coins[0];
            return 1e9;
        }
        int notTake = 0 + f(ind-1,T,coins);
        int take = INT_MAX;
        if(coins[ind] <= T) take = 1 + f(ind,T-coins[ind],coins);
        return min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n-1,amount,coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Approach-2 (Using DP)
class Solution {
public:
    int f(int ind,int T, vector<int> &coins, vector<vector<int>> &dp){
        if(ind==0){
            if((T % coins[0]) == 0) return T/coins[0];
            return 1e9;
        }
        if(dp[ind][T]!=-1) return dp[ind][T];
        int notTake = 0 + f(ind-1,T,coins,dp);
        int take = INT_MAX;
        if(coins[ind] <= T) take = 1 + f(ind,T-coins[ind],coins,dp);
        return dp[ind][T]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Approach-3 (Using Tabulation)

class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int T=0;T<=target;T++){
            if(T % coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=target;T++){
                int notTake = 0 + dp[ind-1][T];
                int take = INT_MAX;
                if(coins[ind] <= T) take = 1 + dp[ind][T-coins[ind]];
                dp[ind][T]=min(take,notTake);
            }
        }
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Approach-4 (Space optimisation in Tabulation)

class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<int> prev(target+1,0), cur(target+1,0);
        for(int T=0;T<=target;T++){
            if(T % coins[0] == 0) prev[T] = T/coins[0];
            else prev[T]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=target;T++){
                int notTake = 0 + prev[T];
                int take = INT_MAX;
                if(coins[ind] <= T) take = 1 + cur[T-coins[ind]];
                cur[T]=min(take,notTake);
            }
            prev=cur;
        }
        int ans = prev[target];
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Que 2 -> Ways To Make Coin Change

// Approach-1 (Using Recursion)

long f(int ind,int T, int *a){
    if(ind==0){
        return (T%a[0]==0);
    }
    long notTake = f(ind-1,T,a);
    long Take=0;
    if(a[ind]<=T) Take=f(ind,T-a[ind],a);
    return notTake+Take;
}
long countWaysToMakeChange(int *arr, int n, int T)
{
    //Write your code here
    return f(n-1,T,arr);
   
}

// Approach-2 (Using DP)

long f(int ind,int T, int *a, vector<vector<long>> &dp){
    if(ind==0){
        return (T%a[0]==0);
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    long notTake = f(ind-1,T,a,dp);
    long Take=0;
    if(a[ind]<=T) Take=f(ind,T-a[ind],a,dp);
    return dp[ind][T]=notTake+Take;
}
long countWaysToMakeChange(int *arr, int n, int T)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(T+1,-1));
    return f(n-1,T,arr,dp);
   
}

// Approach-3 (Using Tabulation)

long countWaysToMakeChange(int *arr, int n, int target)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(target+1,0));
    for(int T=0;T<=target;T++){
        dp[0][T]= (T%arr[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            long notTake = dp[ind-1][T];
            long Take=0;
            if(arr[ind]<=T) Take=dp[ind][T-arr[ind]];
            dp[ind][T]=notTake+Take;
        }
    }
    return dp[n-1][target];
   
}

// Approach-4 (Space optimisation in Tabulation)

long countWaysToMakeChange(int *arr, int n, int target)
{
    //Write your code here
    vector<long> prev(target+1,0), cur(target+1,0);
    for(int T=0;T<=target;T++){
        prev[T]= (T%arr[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            long notTake = prev[T];
            long Take=0;
            if(arr[ind]<=T) Take=cur[T-arr[ind]];
            cur[T]=notTake+Take;
        }
        prev=cur;
    }
    return prev[target];
   
}