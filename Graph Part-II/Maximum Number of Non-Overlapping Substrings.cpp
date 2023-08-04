#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s){
        vector<string> ans;
        map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]][1]=i;
            }else{
                mp[s[i]]={i,i};
            }
        }
        int substringStart=-1;
        for(int i=0;i<s.length();i++){
            int start=mp[s[i]][0];
            if(start==i){
                int substringEnd=End(s,mp,i);
                if(substringEnd!=-1){
                    if(substringEnd>substringStart)
                        ans.push_back("");
                    substringStart=substringEnd;
                    ans[ans.size()-1]=s.substr(i,substringEnd-i+1);
                }
                
            }
        }
        return ans;
    }
    int End(string s,map<char,vector<int>> &mp,int start){
        int end=mp[s[start]][1];
        for(int i=start;i<end;i++){
            if(mp[s[i]][0]<start) return -1;
            end=max(end,mp[s[i]][1]);
        }
        return end;
    }
};