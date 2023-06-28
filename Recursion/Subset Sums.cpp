//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    // Approach-1 (PowerSet)
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        int sum=0;
        for(int i=0;i<(1<<n);i++){
            sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=arr[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }

    // Approach-2 (Recursion)

    void func(int index,int sum,vector<int> &arr,int n,vector<int> &subsetSum){
        if(index==n){
            subsetSum.push_back(sum);
            return;
        }
        // pick that index sum and move forward
        func(index+1,sum+arr[index],arr,n,subsetSum);
        // leave that index sum and move forward
        func(index+1,sum,arr,n,subsetSum);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> subsetSum;
        func(0,0,arr,n,subsetSum);
        sort(subsetSum.begin(),subsetSum.end());
        return subsetSum;
    }
};

