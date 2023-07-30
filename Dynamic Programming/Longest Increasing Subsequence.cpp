#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>seq;
	seq.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(seq.back()<arr[i]){
			seq.push_back(arr[i]);
		}
		else{
			int ind = lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
			seq[ind]=arr[i];
		}
	}

	return seq.size();
}
