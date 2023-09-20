#include<bits/stdc++.h>

using namespace std;

// Approach -1 (Using Recursion)
class Solution {
public:
    // To check any word in O(1) time
    unordered_set<string> st;
    int n;
    bool solve(int idx,string s){
        if(idx==n) return true;
        if(st.find(s.substr(idx,n-idx))!=st.end()) return true;
        for(int l=1;l<=n-idx;l++){
            if(st.find(s.substr(idx,l))!=st.end() && solve(idx+l,s)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto it : wordDict){
            st.insert(it);
        }
        return solve(0,s);
    }
};

// Approach -2 (Using DP)

class Solution {
public:
    // To check any word in O(1) time
    unordered_set<string> st;
    int n;
    bool solve(int idx,string s,vector<int> &dp){
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s.substr(idx,n-idx))!=st.end()) return true;
        for(int l=1;l<=n-idx;l++){
            if(st.find(s.substr(idx,l))!=st.end() && solve(idx+l,s,dp)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto it : wordDict){
            st.insert(it);
        }
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};

// Approach -3 (Using Tabulation)

class Solution {
public:
    // To check any word in O(1) time
    unordered_set<string> st;
    int n;
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto it : wordDict){
            st.insert(it);
        }
        vector<bool> dp(n+1,false);
        dp[n]=true;
        // Only this loop will also work instead of one given below
        // for(int idx=n-1;idx>=0;idx--){
        //     for(int l=1;l<=n-idx;l++){
        //         if(st.find(s.substr(idx,l))!=st.end() && dp[idx+l]){
        //             dp[idx]=true;
        //         }
        //     }
        // }
        for(int idx=n-1;idx>=0;idx--){
            int flag=0;
            if(st.find(s.substr(idx,n-idx))!=st.end()){
                flag=1;
                dp[idx]= true;
            } 
            if(!flag){
                for(int l=1;l<=n-idx;l++){
                    if(st.find(s.substr(idx,l))!=st.end() && dp[idx+l]){
                        flag=1;
                        dp[idx]=true;
                    }
                }
            }
            if(!flag) dp[idx]=false;
        }
        return dp[0];
    }
};