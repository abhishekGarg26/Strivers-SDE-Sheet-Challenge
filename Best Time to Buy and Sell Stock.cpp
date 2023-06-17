#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini=nums[0],profit=0,cost=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            cost=nums[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,nums[i]);
        }
        return profit;
    }
};