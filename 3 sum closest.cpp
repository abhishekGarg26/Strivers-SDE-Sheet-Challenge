#include <bits/stdc++.h> 

using namespace std;


class Solution{
    public:
    int closest3Sum(int nums[], int n, int X)
    {
        int ans=INT_MAX;
        sort(nums,nums+n);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==X) return X;
                if(abs(X-sum)<=abs(X-ans)){
                        ans=sum;
                }
                if(sum<X) j++;
                if(sum>X) k--;
                    
            }
        }
        return ans;
    }
};