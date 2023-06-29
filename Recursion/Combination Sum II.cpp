#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:

// Approach-1 (Modify recursion for combination sum-1)

void findCombination(int ind,int target,vector<int>& arr, set<vector<int>> &ans,vector<int> &ds){
        
        if(ind==arr.size()){
            if(target==0){
                ans.insert(ds);
            }
            return;
        }
    //    pick up the element
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findCombination(ind+1,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
    findCombination(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        findCombination(0,target,candidates,ans,ds);
        return vector<vector<int>> (ans.begin(),ans.end());
    }

    // Approach-2 

    void findComb(int ind,int target,vector<int>& arr, vector<vector<int>> &ans,vector<int> &ds){
        
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        //    pick up the element
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findComb(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findComb(0,target,candidates,ans,ds);
        return ans;
    }
};