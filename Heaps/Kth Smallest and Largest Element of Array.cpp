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

// Approach-2 (maintaining only k-sized heaps)

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	// Write your code here.
		priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<k;i++){
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(nums[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return {maxHeap.top(),minHeap.top()};
}
