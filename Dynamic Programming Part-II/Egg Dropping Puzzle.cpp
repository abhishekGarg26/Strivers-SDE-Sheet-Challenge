#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Recursion)

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp = 1+max(solve(e-1,k-1),solve(e,f-k));
            mn=min(mn,temp);
        }
        return mn;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        return solve(e,f);
    }
};

// Approach-2 (Using DP)

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f,vector<vector<int>> &dp){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp = 1+max(solve(e-1,k-1,dp),solve(e,f-k,dp));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
    }
};

// Approach-3 (Using Tabulation)

int eggDrop(int totEggs, int totFloors) 
    {
        // your code here
        vector<vector<int>>dp(totEggs+1,vector<int>(totFloors+1,0));
        // Base Case for floors
        for(int e=0;e<=totEggs;e++){
            dp[e][0]=0;
            dp[e][1]=1;
        }
        // Base Case for eggs
        for(int f=0;f<=totFloors;f++){
            dp[1][f]=f;
        }
        for(int e=2;e<=totEggs;e++){
            for(int f=2;f<=totFloors;f++){
                int mn=INT_MAX;
                for(int k=1;k<=f;k++){
                    int temp = 1+max(dp[e-1][k-1],dp[e][f-k]);
                    mn=min(mn,temp);
                }
                dp[e][f]=mn;
            }
        }
        return dp[totEggs][totFloors];
    }

    // Approach-4 (Space optimisation in Tabulation)

    int eggDrop(int totEggs, int totFloors) 
    {
        // your code here
        vector<int> prev(totFloors+1,0), cur(totFloors+1,0);
        // Base Case for floors
        cur[0]=0;
        cur[1]=1;
        // Base Case for eggs
        for(int f=0;f<=totFloors;f++){
            prev[f]=f;
        }
        
        for(int e=2;e<=totEggs;e++){
            for(int f=2;f<=totFloors;f++){
                int mn=INT_MAX;
                for(int k=1;k<=f;k++){
                    int temp = 1+max(prev[k-1],cur[f-k]);
                    mn=min(mn,temp);
                }
                cur[f]=mn;
            }
            prev=cur;
        }
        return prev[totFloors];
    }