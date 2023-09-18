#include <bits/stdc++.h> 
using namespace std;

// Approach - 1 (Using Recursion)
class Solution {
public:
    int f(int i, vector<vector<int>> &job, vector<int> startTime,int n){
      if(i==n) return 0;
      int index = lower_bound(startTime.begin(),startTime.end(),job[i][1]) - startTime.begin();
      int pick = job[i][2] + f(index,job,startTime,n);
      int notPick = f(i+1,job,startTime,n);
      return max(pick,notPick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job;
        for(int i=0;i<n;i++){
          job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return f(0,job,startTime,n);
    }
};

// Approach - 2 (Using DP)
class Solution {
public:
    int f(int i, vector<vector<int>> &job, vector<int> startTime,int n, vector<int> &dp){
      if(i==n) return 0;
      if(dp[i]!=-1) return dp[i];
      int index = lower_bound(startTime.begin(),startTime.end(),job[i][1]) - startTime.begin();
      int pick = job[i][2] + f(index,job,startTime,n,dp);
      int notPick = f(i+1,job,startTime,n,dp);
      return dp[i]=max(pick,notPick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job;
        for(int i=0;i<n;i++){
          job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        vector<int> dp(n,-1);
        return f(0,job,startTime,n,dp);
    }
};

// Approach - 3 (Using Tabulation)

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job;
        for(int i=0;i<n;i++){
          job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int index = lower_bound(startTime.begin(),startTime.end(),job[i][1]) - startTime.begin();
            int pick = job[i][2] + dp[index];
            int notPick = dp[i+1];
            dp[i]=max(pick,notPick);
        }
        return dp[0];
    }
};



// Approach - 4 (Using Greedy Approach)

class Solution {
public:
    static int comparator(vector<int> job1,vector<int> job2){
      if(job1[1] <= job2[1]) return true;
      return false;
    }
    // Total Time : n + 2nlogn , Total Space : n
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n=profit.size();
        // Time : O(n)
        for(int i=0;i<n;i++){
          jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        // Time : nlogn
        sort(jobs.begin(),jobs.end(),comparator);
        map<int,int> mp;
        map<int,int> :: iterator it;
        mp[0]=0;
        int maxProfit = 0;
        // Time : nlogn
        for(int i=0;i<n;i++){
          int newProfit = jobs[i][2];
        // Lowerbound or upperbound method takes logn time since map is stored in sorted format in memory

        //   it = mp.lower_bound(jobs[i][0]);

        // The condition check is applied in lowerbound because it give smallest value >= while 
        // upper bound only gives smallest value > given value.

        //   if(it==mp.end() || it->first!=jobs[i][0]) --it;

           it = mp.upper_bound(jobs[i][0]);
          --it;
          newProfit = max(newProfit,newProfit+it->second);
          if(newProfit > maxProfit){
            mp[jobs[i][1]] = newProfit;
            maxProfit = newProfit;
          }
        }
        return maxProfit;
    }
};