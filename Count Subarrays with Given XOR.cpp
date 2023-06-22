#include <bits/stdc++.h>

using namespace std;

int subarraysXor(vector<int> &A, int k)
{
    int xr=0,cnt=0,n=A.size();
    map<int,int> mpp;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^A[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}