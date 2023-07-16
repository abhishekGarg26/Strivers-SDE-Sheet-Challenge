#include <bits/stdc++.h> 
using namespace std;

// Approach-1 (Using Two Pointers) 

int Solve(string str) {
    
    // Write your code here.
    int i=0,j=str.size()-1;
    int trim=j, res=0;
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }else{
            i=0;
            j=--trim;
            res+=1;
        }
    }
    return res;
    


}

// Approach-2 (Using LPS Array)

vector<int> calculateLps(string s){
    vector<int> lps(s.size(),0);
    int j;
    for(int i=1;i<s.size();i++){
        j=lps[i-1];
        while(j>0 && s[j]!=s[i]){
            j=lps[j-1];
        }
        if(s[j]==s[i]) j++;
        lps[i]=j;
    }
    
    return lps;
}
int Solution(string str) {
    
    // Write your code here.
    string rev=str;
    reverse(rev.begin(),rev.end());
    string s=str+'$'+rev;
    vector<int> lps= calculateLps(s);
    return str.size()-lps[s.size()-1];
    


}