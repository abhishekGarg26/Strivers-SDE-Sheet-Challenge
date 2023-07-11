#include <bits/stdc++.h> 
using namespace std;

// Recursive solution

class Solution {
public:
    string func(string s,int ind,string &str){
        string t="";
        for(int i=ind;i<s.size();i++){
            if(!t.size() && s[i]==' ') continue;
            else if(s[i]!=' '){
                t+=s[i];
            }else{
                string k=func(s,i,str);
                if(k.size())
                    str+=k+' ';
                break;
            }
        }
        if(ind==0){
            str+=t;
        } 
        return ind==0? str : t;
    }
    string reverseWords(string s) {
        string str="";
        return func(s,0,str);
    }
};

// Approach -2

 string reverseWords(string s) {
        string ans="";
        vector<string> a;
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int j=i;
            if(i<0) break;
            while(i>=0 && s[i]!=' ') i--;
            if(ans.size()){
                ans+=" "+s.substr(i+1,j-i);
            }else{
                ans+=s.substr(i+1,j-i);
            }
        }
        
        return ans;
    }