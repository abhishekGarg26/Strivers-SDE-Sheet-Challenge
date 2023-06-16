#include <bits/stdc++.h> 
using namespace std;

//  Most Optimal Appraoch for array containing negative elements also alongwith postitive and zeros

int getLongestSubarray(vector<int>& nums, int k){
    map<int, int> preSumMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;

}

// Most Optimal Approach for array containing positive and zeros elements (not for negative elements)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left=0,right=0;
    long long sum=a[0];
    int n=a.size();
    int maxLen=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=a[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n) sum+=a[right];
    }
    return maxLen;

}