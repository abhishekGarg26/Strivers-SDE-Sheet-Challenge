#include <bits/stdc++.h> 
using namespace std;

// Approach -1 (Using Recursion)

class Solution{
public:
    bool isPalindrome(int i,int j,string str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n,string &str){
        if(i==n) return 0;
        int minCost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
                int cost = 1 + f(j+1,n,str);
                minCost = min(minCost,cost);
            }
        }
        return minCost;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        return f(0,n,str)-1;
    }
};

// Approach -2 (Using DP)

class Solution{
public:
    bool isPalindrome(int i,int j,string str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n,string &str,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
                int cost = 1 + f(j+1,n,str,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n+1,-1);
        return f(0,n,str,dp)-1;
    }
};

// Approach -3 (Using Tabulation)
class Solution{
public:
    bool isPalindrome(int i,int j,string str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,str)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
};