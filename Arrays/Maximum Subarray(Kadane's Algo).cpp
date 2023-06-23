#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int n=nums.size(),start=0,ansStart=-1,ansEnd=-1;
        for(int i=0;i<n;i++){
            if(sum==0) start=i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                ansStart=start;
                ansEnd=i;
            }
            if(sum<0) sum=0;
        }

        while(ansStart<=ansEnd){
            cout<<nums[ansStart++]<<" ";
        }
        return maxi;
    }
};