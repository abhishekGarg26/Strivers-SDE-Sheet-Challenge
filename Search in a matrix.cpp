#include<bits/stdc++.h>

using namespace std;

// GFG solutions when first element of second row is not greater then last element of first row
class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int n, int m, int target)
	{
     int i=0,j=m-1;
     while(i<n && j>=0){
         if(matrix[i][j]==target){
             return 1;
         }
         else if(matrix[i][j]<target){
             i++;
         }else{
             j--;
         }
     }
         return 0;
	}
};

// Leetcode solutions when first element of second row is greater then last element of first row

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
    if(!arr.size()) return false;
     int n=arr.size(),m=arr[0].size();
     int low=0,high=(m*n)-1;
     while(low<=high){
         int mid=(low+(high-low)/2);
         if(arr[mid/m][mid%m]==target){
             return true;
         }else if(arr[mid/m][mid%m]<target){
             low=mid+1;
         }else{
             high=mid-1;
         }
     }
    return false;
    }
};