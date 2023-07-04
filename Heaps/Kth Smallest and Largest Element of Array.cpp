#include<bits/stdc++.h>

using namespace std;

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	// Write your code here.
		priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int>> minh;
        for(auto it:nums){
            pq.push(it);
			minh.push(it);
        }
        for(int i=k-1;i>0;i--){
            pq.pop();
			minh.pop();
        }
        return {minh.top(),pq.top()};
}