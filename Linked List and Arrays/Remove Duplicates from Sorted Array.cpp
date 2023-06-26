#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size(),i=0;
        for(int j=1;j<n;j++){
            if(arr[j]!=arr[i]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        return (i+1);
    }
};