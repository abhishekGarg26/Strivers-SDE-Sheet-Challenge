#include <bits/stdc++.h> 

using namespace std;

int findMinimumCoins(int V) 
{
    // Write your code here
        int deno[]={1,2,5,10,20,50,100,500,1000};
        int n=9;
	    int cnt=0;
        vector<int> ans;
	    for(int i=n-1;i>=0;i--){
	        while(V>=deno[i]){
	            V-=deno[i];
	            cnt++;
                ans.push_back(deno[i]);
	        }
	    }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
	    return cnt;
}
