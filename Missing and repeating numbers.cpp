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

// Approach using XOR

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr=0;
	for(int i=0;i<n;i++){
		xr =xr^arr[i];
		xr =xr^(i+1);
	}
	int bitNo=0;
	while(1){
		if(xr & (1<<bitNo)==1){
			break;
		}
		bitNo++;
	}
	// int number=xr & ~(xr-1);
	int zero=0;
	int one=0;
	for(int i=0;i<n;i++){
		if((arr[i] & (1<<bitNo)) != 1){
			zero=zero^arr[i];
		}else{
			one=one^arr[i];
		}
	}
	for(int i=1;i<=n;i++){
		if((i & (1<<bitNo))!=1){
			zero=zero^i;
		}else{
			one=one^i;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i] == zero) cnt++;
	}
	if(cnt==2) return {one,zero};
	return {zero,one};
}

