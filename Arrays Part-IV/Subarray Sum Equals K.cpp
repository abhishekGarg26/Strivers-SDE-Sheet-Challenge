#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Approach-1

    // int subarraySum(vector<int>& nums , int k) {
    //     int count = 0;
    //     vector<int> sum[nums.size() + 1];
    //     for (int i = 1; i <= nums.size(); i++)
    //         sum[i] = sum[i - 1] + nums[i - 1];
    //     for (int start = 0; start < nums.size(); start++) {
    //         for (int end = start + 1; end <= nums.size(); end++) {
    //             if (sum[end] - sum[start] == k)
    //                 count++;
    //         }
    //     }
    //     return count;
    // }

    // Approach-2

    //     int subarraySum(int[] nums, int k) {
    //         int count = 0;
    //         for (int start = 0; start < nums.length; start++) {
    //             int sum=0;
    //             for (int end = start; end < nums.length; end++) {
    //                 sum+=nums[end];
    //                 if (sum == k)
    //                     count++;
    //             }
    //         }
    //         return count;
    //     }

    // Appraoch-3

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