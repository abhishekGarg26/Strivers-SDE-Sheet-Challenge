#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
       int i;
       for(i=0;i<s.size();i++){
           if(s[i]==' ') continue;
           else break;
       }
       s.erase(0,i);
       if(s.empty()) return 0;
       long long ans=0;
       bool negative=0;
       if(s[0]=='-') negative=1;
       else if(s[0]=='+') negative=0;
       else if(!isdigit(s[0]))return 0;
       else ans=(int)s[0]-(int)('0');

       for(i=1;i<s.size();i++){
           if(isdigit(s[i])){
               ans=ans*10+((int)s[i]- (int)('0')); // can be done also as : s[i]-'0' or int(s[i])-int('0')
               if(!negative && ans>INT_MAX) return INT_MAX;
               else if(negative && (-ans)<INT_MIN) return INT_MIN; 
           }else break;
       }
       if(!negative) return ans;
       return -ans;

       
    }
};