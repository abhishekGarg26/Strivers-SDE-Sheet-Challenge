#include <bits/stdc++.h> 

using namespace std;

class Solution {
    public:
    void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
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
}
int countPairs(vector<int> arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>(2*(long long)arr[right])) right++;
        cnt+=right-(mid+1);
    }
    return cnt;
}
int mS(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=low+((high-low)/2);
    cnt+=mS(arr,low,mid);
    cnt+=mS(arr,mid+1,high);
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}
    int reversePairs(vector<int>& arr) {
        int n=arr.size();
        return mS(arr,0,n-1);

    }
};