#include <bits/stdc++.h> 
using namespace std;

// Derived from observations
int maxProduct(vector<int>& nums) {
        int pre=1, suff=1, maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            maxi=max(maxi,max(pre,suff));
        }
        return maxi;
}

// Inspired by Kadane's Algo
int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
	int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
