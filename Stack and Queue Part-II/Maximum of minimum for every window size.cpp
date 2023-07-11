#include <bits/stdc++.h> 
using namespace std;

// Approach-1

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> st;
    vector<int> res;
    int left[n];
    int right[n];
    for(int i=0;i<n;i++){
        left[i]=0;
        right[i]=n-1;
    }
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()){
            left[i]=st.top()+1;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()){
            right[i]=st.top()-1;
        }
        st.push(i);
    }
    int ans[n+1];
    for(int i=0;i<n+1;i++) ans[i]=INT_MIN;
    for(int i=0;i<n;i++){
        int len=(right[i]-left[i]+1);
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=1;i<n+1;i++){
        res.push_back(ans[i]);
    }
    return res;

}

// Appraoch-2

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> st;
    vector<int> res;
    int ans[n+1];
    for(int i=0;i<n+1;i++) ans[i]=INT_MIN;
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || a[st.top()]>=a[i])){
            int rightSmall=i-1;
            int leftSmall;
            int el=a[st.top()];
            st.pop();
            if(st.empty()) leftSmall=0;
            else leftSmall=st.top()+1;
            int windowSize=rightSmall-leftSmall+1;
            ans[windowSize]=max(ans[windowSize],el);
        }
        st.push(i);
    }
    for(int i=n-1;i>0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=1;i<n+1;i++){
        res.push_back(ans[i]);
    }
    return res;

}