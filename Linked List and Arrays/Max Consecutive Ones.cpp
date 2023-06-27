
#include <bits/stdc++.h> 

using namespace std;

// Leetcode
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }else{
                 cnt=0;
            }
        }
        return maxi;
        
    }
};

// CodeStudio variation - maximum ones changing at most k zeros

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
        int maxi=0,i=0,j=0,ans=0,flip=0;
        while(i<n){
            if(arr[i]==0) flip++;
            while(flip>k){
                if(arr[j]==0) flip--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        
        return ans;
}
