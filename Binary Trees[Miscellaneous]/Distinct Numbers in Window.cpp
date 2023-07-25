#include <bits/stdc++.h> 
using namespace std;

vector<int> Solution(vector<int> &A, int k) {
    map<int,int> mp;
    vector<int> ans;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(i<k) mp[A[i]]++;
        else{
            if(mp[A[i-k]]>1)
                mp[A[i-k]]--;
            else mp.erase(A[i-k]);
            mp[A[i]]++;
        }
        if(i>=k-1) ans.push_back(mp.size());
    }
    return ans;
}
