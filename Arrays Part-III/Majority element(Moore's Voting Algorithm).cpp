#include <bits/stdc++.h> 
using namespace std;

// Using Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second>(n/2)) return i.first;
        }
        return -1;
    }
};

// Using Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }else if(nums[i]==el){
                cnt++;
            }else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt1++;
        }
        if(cnt1>(n/2)) return el;
        return -1;
    }
};