#include <bits/stdc++.h> 
using namespace std;

// Appraoch-1 

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s="1";
        for(int i=2;i<=n;i++){
            string t="";
            s=s+"$";
            int count=1;
            for(int j=1;j<s.size();j++){
                if(s[j]!=s[j-1]){
                    t+=to_string(count);
                    t+=s[j-1];
                    count=1;
                }else count++;
            }
            s=t;
        }
        return s;
    }
};

// Recursive Approach-2 

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        string res="";
        s=s+"$";
        int count=1;
        for(int j=1;j<s.size();j++){
            if(s[j]!=s[j-1]){
                res+=to_string(count);
                res+=s[j-1];
                count=1;
            }else count++;
        }
        return res;

    }
};