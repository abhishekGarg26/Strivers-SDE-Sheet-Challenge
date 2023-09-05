#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Recursion)

int f(int ind, int N, vector<int> &prices){
    if(ind==0){
        return N*prices[0];
    }
    int notTake = 0 + f(ind-1,N,prices);
    int Take = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N) Take = prices[ind] + f(ind,N-rodLength,prices);
    return max(notTake,Take);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return f(n-1,n,price);
}

// Approach-2 (Using DP)

int f(int ind, int N, vector<int> &prices, vector<vector<int>> &dp){
    if(ind==0){
        return N*prices[0];
    }
    if(dp[ind][N]!=-1) return dp[ind][N];
    int notTake = 0 + f(ind-1,N,prices,dp);
    int Take = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N) Take = prices[ind] + f(ind,N-rodLength,prices,dp);
    return dp[ind][N]=max(notTake,Take);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n,price,dp);
}

// Approach-3 (Using Tabulation)

int cutRod(vector<int> &prices, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int N=0;N<=n;N++){
        dp[0][N]= N*prices[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake = 0 + dp[ind-1][N];
            int Take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= N) Take = prices[ind] + dp[ind][N-rodLength];
            dp[ind][N]=max(notTake,Take);
        }
    }
    return dp[n-1][n];
}

// Approach-4 (Space Optimisation Using 2 1D arrays In Tabulation)

int cutRod(vector<int> &prices, int n)
{
	// Write your code here.
    vector<int> prev(n+1,0),cur(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]= N*prices[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake = 0 + prev[N];
            int Take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= N) Take = prices[ind] + cur[N-rodLength];
            cur[N]=max(notTake,Take);
        }
        prev=cur;
    }
    return prev[n];
}

// Approach-5 (Space Optimisation Using 1 1D array In Tabulation)

int cutRod(vector<int> &prices, int n)
{
	// Write your code here.
    vector<int> prev(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]= N*prices[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake = 0 + prev[N];
            int Take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= N) Take = prices[ind] + prev[N-rodLength];
            prev[N]=max(notTake,Take);
        }
    }
    return prev[n];
}
