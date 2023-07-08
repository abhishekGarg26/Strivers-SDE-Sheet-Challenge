#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){ // Can start loop from 2*n-1 for circular array problem
        while(!st.empty() && arr[i%n]>=st.top()){
            st.pop();
        }
        if(i<n){
            if(st.empty()){
                ans[i%n]=-1;
            }else{
                ans[i%n]=st.top();
            }
        }
        st.push(arr[i%n]);

    }
    return ans;

}