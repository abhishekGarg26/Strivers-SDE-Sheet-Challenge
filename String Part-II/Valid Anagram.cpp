#include <bits/stdc++.h> 
using namespace std;

// Approach-1

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;

    }
};

// Approach-2 

 bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> arr(256,0);
        for(int i=0;i<s.size();i++){
            int index1=s[i];
            int index2=t[i];
            arr[index1]++;
            arr[index2]--;
        }
        for(int i=0;i<s.size();i++){
            int index=s[i];
            if(arr[index]!=0) return false;
        }
        return true;

    }