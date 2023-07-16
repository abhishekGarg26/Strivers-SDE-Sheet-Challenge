#include <bits/stdc++.h> 
using namespace std;

int compareVersions(string v1, string v2) 
{
    // Write your code here
        int v1Len=v1.size();
        int v2Len=v2.size();
        int i=0,j=0;
        long long n1=0,n2=0;
        while(i<v1Len || j<v2Len){
            n1=0;
            n2=0;
            while(i<v1Len && v1[i]!='.'){
                n1=n1*10+(v1[i]-'0');
                i++;
            }
            while(j<v2Len && v2[j]!='.'){
                n2=n2*10+(v2[j]-'0');
                j++;
            }
            if(n1>n2) return 1;
            if(n1<n2) return -1;
            i++;
            j++;
        }
        return 0;
}