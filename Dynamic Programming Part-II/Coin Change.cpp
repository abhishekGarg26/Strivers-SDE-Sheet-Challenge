#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *arr, int n, int T)
{
    //Write your code here
    vector<long> prev(T+1,0);
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
    }
    
    for(int ind=1; ind<n;ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = cur[target-arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
}