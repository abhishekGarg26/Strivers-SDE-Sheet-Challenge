#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Recursion)
class Solution {
public:
    int f(int ind1,int ind2, string str1, string str2){
        if(ind1<0 || ind2<0) return 0;
        if(str1[ind1]==str2[ind2]){
            return 1+f(ind1-1,ind2-1,str1,str2);
        }
        return 0+max(f(ind1-1,ind2,str1,str2),f(ind1,ind2-1,str1,str2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return f(n-1,m-1,text1,text2);
    }
};

// Approach-2 (Using DP)
class Solution {
public:
    int f(int ind1,int ind2, string str1, string str2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]=1+f(ind1-1,ind2-1,str1,str2,dp);
        }
        return dp[ind1][ind2]=max(f(ind1-1,ind2,str1,str2,dp),f(ind1,ind2-1,str1,str2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};

// Approach-3 (Using Tabulation) 

int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // These two loops are for base case 
        // we can also omit these loops by initialising whole dp vector with 0 
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }

        // To print LCS as well we can do below steps

        int len=dp[n][m];
        string ans="";
        for(int i=0;i<len;i++) ans+='$';
        int i=n, j=m, index=len-1;
        // O(n+m) at worst case
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans[index]=text1[i-1];
                index--;
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i=i-1;
            }else{
                j=j-1;
            }
        }
        // Printing the lcs
        cout<<ans;

        // returning length of lcs
        return dp[n][m];
}

// Approach-4 (Using Space optimisation tech. in Tabulation)

int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    cur[ind2]=1+prev[ind2-1];
                }
                else cur[ind2]=max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        return prev[m];
}

