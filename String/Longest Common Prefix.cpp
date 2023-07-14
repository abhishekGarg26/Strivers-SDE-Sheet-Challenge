#include <bits/stdc++.h> 
using namespace std;

// Approach-1

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans="";
    bool match=true;
    // for traversing all characters first string
    for(int i=0;i<arr[0].size();i++){
        char ch=arr[0][i];
        // for comparing ch with rest of the strings
        for(int j=1;j<arr.size();j++){
            // not match
            if(arr[j].size()<i+1 || ch!=arr[j][i]){
                match=false; // can return ans here also
                break;
            }
        }
        if(match==false) break;
        else ans+=ch;
    }
    return ans;
}

// Approach -2 (Using Sorting)

 string longestCommonPrefix(vector<string>& arr) {
    int n=arr.size();
    string ans="";
    sort(arr.begin(),arr.end());  
    for(int i=0;i<arr[0].size();i++){
        if(arr[0][i]==arr[n-1][i])
        ans+=arr[0][i];
        else break;
    }
    return ans;
    }


