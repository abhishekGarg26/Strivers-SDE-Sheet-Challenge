#include<bits/stdc++.h>

using namespace std;

// Better Approach using O(2N) time and O(1) space

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) c0++;
            else if(nums[i]==1) c1++;
            else c2++;
        }
        for(int i=0;i<c0;i++){
            nums[i]=0;
        }
        for(int i=c0;i<c0+c1;i++){
            nums[i]=1;
        }
        for(int i=c0+c1;i<n;i++){
            nums[i]=2;
        }
        return;
    }
};

// Optimal Approach using O(N) time and O(1) space

void sortColors(vector<int>& nums) {
        int mid=0,low=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return ;
    }