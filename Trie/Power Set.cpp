#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pwset(vector<int>nums)
{
    //Write your code here
    vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            ans.push_back({});
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ans[ans.size()-1].push_back(nums[j]);
                }
            }
        }
        return ans;
}