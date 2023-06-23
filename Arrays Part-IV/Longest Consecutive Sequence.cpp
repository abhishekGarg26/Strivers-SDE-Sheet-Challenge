#include <bits/stdc++.h>
using namespace std;

// Approach-1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),lastSmaller=INT_MIN,cntCur=0,longest=1;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSmaller){
                cntCur+=1;
                lastSmaller=nums[i];
            }else if(nums[i]!=lastSmaller){
                cntCur=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,cntCur);
        }
        return longest;
    }
};

// Approach-2

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=1,n=nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};