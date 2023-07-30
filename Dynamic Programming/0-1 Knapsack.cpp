#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	// Write your code here
	vector<int> prev(W+1,0);
    
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}