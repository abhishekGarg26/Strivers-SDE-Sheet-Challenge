#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    // Approach-1 (Using Set)
    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            ans.push_back({});
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ans[ans.size()-1].push_back(nums[j]);
                }
            }
            sort(ans[ans.size()-1].begin(),ans[ans.size()-1].end());
        }
        set<vector<int>> copy(ans.begin(),ans.end());
        vector<vector<int>> ans1(copy.begin(),copy.end());
        return ans1;
    }

    // Approach-2 (Using optimised recursive approach)
    void findSubsets(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }
};