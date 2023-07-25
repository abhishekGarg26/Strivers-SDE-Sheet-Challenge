#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int quickSelect(vector<int> &nums,int left,int right,int k){
        int pivot=nums[right], p=left;
        for(int i=left;i<right;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[p]);
                p++;
            }
        }
        swap(nums[p],nums[right]);
        if(p>k) return quickSelect(nums,left,p-1,k);
        else if(p<k) return quickSelect(nums,p+1,right,k);
        return nums[p];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickSelect(nums,0,n-1,n-k);
    }
};