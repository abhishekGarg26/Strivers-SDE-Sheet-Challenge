#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
       stack<char> st;
       for(int i=0;i<str.size();i++){
           if(str[i]=='{' || str[i]=='(' || str[i]=='['){
               st.push(str[i]);
           }else{
               if(st.empty()) return false;
               char c=st.top();
               if((str[i]==')' && c=='(') || (str[i]=='}' && c=='{') || (str[i]==']' && c=='[')){
                   st.pop();
               }else return false;
           }
       }
       if(st.empty()) return true;
       return false;
        
    }
};