#include <bits/stdc++.h> 
using namespace std;

bool inDict(string s,vector<string> wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    void solve(int ind,string s, vector<string> &ans,string str,vector<string> &wordDict){
        if(ind==s.size()){
            ans.push_back(str.substr(0,str.size()-1));
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(inDict(s.substr(ind,i-ind+1),wordDict)){
                str+=s.substr(ind,i-ind+1)+" ";
                solve(i+1,s,ans,str,wordDict);
                str.erase(str.size()-(i-ind+2),i-ind+2);
            }
        }
    }
vector<string> getAllValidSentences(string &s, vector<string> &wordDict)
{
    //  write your code here.
	vector<string> ans;
     string str="";
     solve(0,s,ans,str,wordDict);
     return ans;
}