#include<bits/stdc++.h>
using namespace std;

// Approach-1 (Using Recursion)
class Solution {
public:
    int f(int ind, int prev_ind, vector<int> nums, int n){
        if(ind==n) return 0;
        int len= 0 + f(ind+1,prev_ind,nums,n);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            len=max(len,1+f(ind+1,ind,nums,n));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return f(0,-1,nums,nums.size());
    }
};

// Approach-2 (Using DP)
class Solution {
public:
    int f(int ind, int prev_ind, vector<int> nums, int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len= 0 + f(ind+1,prev_ind,nums,n,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            len=max(len,1+f(ind+1,ind,nums,n,dp));
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};

// Space Optimisation by not using auxiliary space of recursion -> O(N^2)

int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int len= 0 + dp[ind+1][prev_ind+1];
                if(prev_ind==-1 || nums[ind]>nums[prev_ind])
                    len=max(len,1+dp[ind+1][ind+1]);
                dp[ind][prev_ind+1]=len;
            }
        }
        return dp[0][-1+1];
    }

// Space Optimisation -> O(2N)

int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
        vector<int> next(n+1,0), cur(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int len= 0 + next[prev_ind+1];
                if(prev_ind==-1 || nums[ind]>nums[prev_ind])
                    len=max(len,1+next[ind+1]);
                cur[prev_ind+1]=len;
            }
            next=cur;
        }
        return next[-1+1];

}

// Approach - (Using Tabulation)

int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }

// Printing LIS using Tabulation

int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=1;
        int lastIndex=0;
		// O(N^2) TC
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev] > dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> lis;
        lis.push_back(nums[lastIndex]);
		// O(N) TC -> when sorted array is given as input
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(),lis.end());
        for(auto it: lis) cout<<it<<" ";
        cout<<endl;
        return maxi;
    }

// Approach (Using Binary Search)

	int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;  // len of lis
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind= lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }