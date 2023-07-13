#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // Approach - 1 (Expanding Centers Method)

    string longestPalindrome(string str) {
    string res="";
    int resLen=0;
    for(int i=0;i<str.size();i++){
        int l=i, r=i;
        while(l>=0 && r<str.size() && str[l]==str[r]){
            if(r-l+1 > resLen){
                res=str.substr(l,r-l+1);
                resLen=r-l+1;
            }
            l--, r++;
        }
        l=i, r=i+1;
         while(l>=0 && r<str.size() && str[l]==str[r]){
            if(r-l+1 > resLen){
                res=str.substr(l,r-l+1);
                resLen=r-l+1;
            }
            l--, r++;
        }

    }
    return res;
    }

    // Approach-2 (Using DP) 

    string longestPalindrome(string str) {
        int n=str.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxLength=0;
        string ans;
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff+i;j<n;i++,j++){
                if(i==j) dp[i][j]=1;
                else if(diff==1){ 
                    dp[i][j]= (str[i]==str[j])?2:0;
                }
                else if (str[i]==str[j] && dp[i+1][j-1]){
                        dp[i][j]=dp[i+1][j-1]+2;
                }
                if(dp[i][j]>maxLength){
                    maxLength=dp[i][j];
                    ans=str.substr(i,maxLength);
                    
                }
            }
        }
        return ans;
    }
};