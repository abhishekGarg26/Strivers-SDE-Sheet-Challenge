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

// Approach - 5 (Recursion using DP and Binary Search)

// We will use binary search instead linear serach in recursive dp soln
// Time Complexity: O((n * k) * logn ) [n = totalFloors , k = totalEggs]
// Space Complexity: O(n * k)
class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(k-1,mid-1,memo);   //egg broken check for down floors of mid
            int right=find(k,n-mid,memo) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};

// Approach - 6 (Time complexity optimisation using binary search since one row is incresing and other is decreasing)
// TC : same as Approach 5
// SC : O(2*totalFloors)

class Solution {
public:
    int superEggDrop(int totEggs, int totFloors) {
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
                int lo=1,hi=f;
                while(lo<=hi){
                    int mid=(lo+hi)>>1;
                    int left = prev[mid-1]; // It is a decreasing func of floors (Break Case)
                    int right = cur[f-mid]; // It is incresing func of floors (Not Break Case)
                    int temp = 1+max(left,right);
                    if(left<right) lo = mid+1; // Since we want to maximise our attempts in worst case (i.e. value of temp),
                    // and worst case will only occur when we have less number of eggs then floors are more in number to explore,
                    // so we need to increase the value of floors as value of right(incr. func of floors) will increase if value of mid will increase and 
                    // value of mid will increase if value of "lo" will increase so that we can explore the worst possible cases.
                    else hi = mid - 1;
                    mn=min(mn,temp);
                }
                cur[f]=mn;
                }
            prev=cur;
            }
        return prev[totFloors];
    }
};

