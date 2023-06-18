#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// S-SN = x-y
	// S2-S2N = x2-y2
	long long S=0,S2=0;
	long long SN=(n*(n+1))/2;
	long long S2N=(n*(n+1)*(2*n+1))/6;
	for(int i=0;i<n;i++){
		S+=arr[i];
		S2+=(long long) arr[i]* (long long) arr[i];
	}
	long long val1=S-SN; //x-y
	long long val2=S2-S2N; // x2-y2
	val2=val2/val1; // x+y
	long long x=(val1+val2)/2;
	long long y=x-val1;
	return {(int)x,(int)y};
}
