#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nm=n;
        if(nm<0) nm*=(-1);
        while(nm>0){
            if(nm%2){
                ans*=x;
                nm-=1;
            }else{
                x*=x;
                nm/=2;
            }
        }
        if(n<0) return (double)(1.0/ans);

        return ans;
    }
};