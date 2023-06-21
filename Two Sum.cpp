#include <bits/stdc++.h> 

using namespace std;

// Using Hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int moreNeeded=target-nums[i];
            if(mpp.find(moreNeeded)!=mpp.end()) return {mpp[moreNeeded],i};
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

// Approach to find out all possible value parirs

vector<vector<int>> pairSum(vector<int> &arr, int s){
          int n = arr.size();
    vector< vector<int> > ans;
        
    // Checking sum for every element.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[j];
                ans.push_back(pair);
            }
        }
    }

    // Used to store final sorted result.
    vector<vector<int> > res(ans.size(),vector<int>(2,0));
    for(int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];

        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }
    sort(res.begin(),res.end());  
    return res;
}