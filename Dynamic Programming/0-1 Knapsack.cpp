#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind,int W,int wt[],int val[]){
        if(ind==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        int notTake=0+f(ind-1,W,wt,val);
        int take=INT_MIN;
        if(wt[ind]<=W){
            take=val[ind]+f(ind-1,W-wt[ind],wt,val);
        }
        return max(notTake,take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return f(n-1,W,wt,val);
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind,int W,int wt[],int val[],vector<vector<int>> &dp){
        if(ind==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notTake=0+f(ind-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=W){
            take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);
        }
        return dp[ind][W]=max(notTake,take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    }
};


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
       for(int W=wt[0];W<=maxWeight;W++) dp[0][W]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int W=0;W<=maxWeight;W++){
                int notTake=0+dp[ind-1][W];
                int take=INT_MIN;
                if(wt[ind]<=W){
                    take=val[ind]+dp[ind-1][W-wt[ind]];
                }
                dp[ind][W]=max(notTake,take);
           }
       }
       return dp[n-1][maxWeight];
    }
};



class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(maxWeight+1,0), cur(maxWeight+1,0);
       for(int W=wt[0];W<=maxWeight;W++) prev[W]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int W=0;W<=maxWeight;W++){
                int notTake=0+prev[W];
                int take=INT_MIN;
                if(wt[ind]<=W){
                    take=val[ind]+prev[W-wt[ind]];
                }
                cur[W]=max(notTake,take);
           }
           prev=cur;
       }
       return prev[maxWeight];
    }
};

// Single Array Space optimisation
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(maxWeight+1,0);
       for(int W=wt[0];W<=maxWeight;W++) prev[W]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int W=maxWeight;W>=0;W--){
                int notTake=0+prev[W];
                int take=INT_MIN;
                if(wt[ind]<=W){
                    take=val[ind]+prev[W-wt[ind]];
                }
                prev[W]=max(notTake,take);
           }
       }
       return prev[maxWeight];
    }
};




