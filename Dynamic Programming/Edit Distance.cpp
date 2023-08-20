#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Recursion)
class Solution {
public:
    int f(int i,int j, string &s1,string &s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j]) return 0+f(i-1,j-1,s1,s2);
        return 1+min(f(i,j-1,s1,s2),min(f(i-1,j,s1,s2),f(i-1,j-1,s1,s2)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(n-1,m-1,word1,word2);
    }
};

// Approach-2 (Using DP) 

class Solution {
public:
    int f(int i,int j, string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=0+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};

// Approach-3  (Using Tabulation)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=0+dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }

         // Tracing back steps of inserting, deleting and replacing
        int i=n,j=m;
        string s="";
        while(i>0 && j>0){
            int mini=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            if(word1[i-1]==word2[j-1]){
                i--,j--;
            }
            else if(mini==dp[i][j-1]){ //check for insert
                j--;
                s+='i';
            }else if(mini==dp[i-1][j]){ //check for delete
                i--;
                s+='d';
            }else{ //check for replacing
                i--;
                j--;
                s+='r';
            }
        }
        reverse(s.begin(),s.end());
        cout<<s;
        return dp[n][m];
    }
};

// Approach-4 (Space optimisation to 1-D Arrays in Tabulation)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) cur[j]=0+prev[j-1];
                else cur[j]=1+min(cur[j-1],min(prev[j],prev[j-1]));
            }
            prev=cur;
        }
        return prev[m];
    }
};