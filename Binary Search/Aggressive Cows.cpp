#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls,int mid,int k){
    int cows=1, last=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last>=mid){
            cows++;
            last=stalls[i];
        }
        if(cows>=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1, high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)>>1;
        if(canWePlace(stalls,mid,k)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}