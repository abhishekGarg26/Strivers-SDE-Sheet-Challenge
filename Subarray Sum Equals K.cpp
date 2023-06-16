#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    map<int, int> preSumMap={{0,1}};
    int sum=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){  
            count+=preSumMap[rem];
        }
        if(preSumMap.find(sum)!=preSumMap.end()){
            preSumMap[sum]+=1;
        }else{
            preSumMap[sum]=1;
        }
    }
    return count;
    }
};