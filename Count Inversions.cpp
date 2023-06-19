#include <bits/stdc++.h> 
using namespace std;

int merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}
int mS(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mS(arr,low,mid);
    cnt+=mS(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
long long getInversions(long long *nums, int n){
    // Write your code here.
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        return mS(arr,0,n-1);
}