#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
   void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1,int ind2){
        if(arr1[ind1]>arr2[ind2]){
            swap(arr1[ind1],arr2[ind2]);
        }
    }

    // TC->O(log2(m+n))*O(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=n+m;
        int gap=(len/2)+(len%2);
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<m && right>=m){
                    swapIfGreater(nums1,nums2,left,right-m);
                }else if(left>=m){
                    swapIfGreater(nums2,nums2,left-m,right-m);
                }else{
                    swapIfGreater(nums1,nums1,left,right);
                }
                left++,right++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }        
        for(int i=m;i<n+m;i++){
            nums1[i]=nums2[i-m];
        }
    }
};

//when we need to get 2 arrays sorted considering them as a single sequence without using extra space     
// TC -> O(min(n,m))+O(nlogn)+O(mlogm)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--,right++;
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
}