#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Approach-1

    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int leftMax=0,rightMax=0;
        int res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax) leftMax=height[left];
                else res+=leftMax-height[left];
                left++;
            }else{
                if(height[right]>=rightMax) rightMax=height[right];
                else res+=rightMax-height[right];
                right--;
            }
        }
        return res;
        
    }

    // Approach-2

    long getTrappedWater(long *height, int n){
    // Write your code here.
        long pre[n];
        long suf[n];
        long maxl=height[0];
        long maxr=height[n-1];
        long cnt=0;
        for(int i=0;i<n;i++){
            if(height[i]>maxl){
                maxl=height[i];
            }
            pre[i]=maxl;
        }
        for(int i=n-1;i>=0;i--){
            if(height[i]>maxr){
                maxr=height[i];
            }
            suf[i]=maxr;
        }
        for(int i=0;i<n;i++){
            cnt+=min(pre[i],suf[i])-height[i];
        }
        return cnt;
}
};