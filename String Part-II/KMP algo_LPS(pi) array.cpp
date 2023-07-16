#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> strStr(string test, string pattern) {
        vector<int> lps(pattern.size(),0);
        int j;
        for(int i=1;i<pattern.size();i++){
            j=lps[i-1];
            while(j>0 && pattern[j]!=pattern[i]){
                j=lps[j-1];
            }
            if(pattern[j]==pattern[i]) j++;
            lps[i]=j;
        }
        int i=0;
        j=0;
        vector<int> pos;
        while(i<test.size()){
            if(test[i]==pattern[j]){
                i++;
                j++;
            }
            if(j==pattern.size()){
                pos.push_back(i-j+1); //store all the indexes of matching pattern in test string
            }
            else if(test[i]!=pattern[j]){
                if(j==0) i++;
                else j=lps[j-1];

            }
        }
        return pos;


    }
};