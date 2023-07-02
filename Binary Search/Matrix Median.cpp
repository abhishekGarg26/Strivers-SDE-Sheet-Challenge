#include<bits/stdc++.h>
using namespace std;

// Brute Force

int getMedian(vector<vector<int>> &a)
{
    // Write your code here.
    int n=a.size(),m=a[0].size();
    vector<int> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b.push_back(a[i][j]);
        }
    }
    sort(b.begin(),b.end());
    int med=b.size()/2;
    return b[med];

}

// Binary Search Approach

int func(vector<int>&a, int m){
    int low=0;
    int high=a.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(a[mid]<=m) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int getMedian(vector<vector<int>> &a)
{
    // Write your code here.
    int n=a.size();
    int m=a[0].size();
    int low=1;
    int high=1e5;
    while(low<=high){
        int cnt=0;
        int mid=(low+high)>>1;
        for(int i=0;i<n;i++){
            cnt+=func(a[i],mid);
        }
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;



}