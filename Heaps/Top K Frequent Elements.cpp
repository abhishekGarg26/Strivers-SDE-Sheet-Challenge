#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // Approach using max heap

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]!=nums[i-1]){
                pq.push(make_pair(cnt,nums[i-1]));
                cnt=1;
            }else
            cnt++;
        }
        pq.push(make_pair(cnt,nums[nums.size()-1]));
        for(int i=k;i>0;i--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    // Optimised Linear time approach

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> countValue(nums.size()+1);
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            countValue[it.second].push_back(it.first);
        }
        for(int i=countValue.size()-1;i>0;i--){
            if(!countValue[i].empty()){
                for(auto it:countValue[i]){
                    ans.push_back(it);
                    if(ans.size()==k) return ans;
                }
            }
        }
        return ans;
    }
};