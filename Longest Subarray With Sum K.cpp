#include <bits/stdc++.h> 
using namespace std;

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