#include <bits/stdc++.h> 
using namespace std;

// Variation of subset sum equals K problem

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.
        vector<bool> prev(k+1,0), cur(k+1,0);
        prev[0] = cur[0] = true;
        if(arr[0]<=k)
            prev[arr[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notTake= prev[target];
                bool take = false;
                if(arr[ind]<= target) take = prev[target-arr[ind]];
                cur[target] = take | notTake;
            }
            prev=cur;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int target = sum/2;
        if(sum % 2) return false;
        return subsetSumToK(n,target,nums);
    }
};