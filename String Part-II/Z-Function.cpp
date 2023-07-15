#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> calculateZ(string pattern){
        vector<int> Z(pattern.size(),0);
        int left=0;
        int right=0;
        int n=pattern.size();
        for(int k=1;k<n;k++){
            if(k>right){
                left=right=k;
                while(right<n && pattern[right]==pattern[right-left]){
                    right++;
                }
                Z[k]=right-left;
                right--;
            }else{
                // We are operating inside box
                int k1=k-left;
                // If the value doesn't stretches till the right bound then just copy it
                if(Z[k1]<right-k+1) Z[k]=Z[k1];
                else{
                    // otherwise try to see if their are more matches
                    left=k;
                    while(right<n && pattern[right]==pattern[right-left]){
                        right++;
                    }
                    Z[k]=right-left;
                    right--;
                }
            }
        }
        return Z;
    }
    int strStr(string text, string pattern) {
        int n=pattern.size();
        pattern+='$'+text;
        vector<int> Z=calculateZ(pattern);
        for(int i=0;i<Z.size();i++){
            if(Z[i]==n) return i-n-1;
        }
        return -1;


    }
};