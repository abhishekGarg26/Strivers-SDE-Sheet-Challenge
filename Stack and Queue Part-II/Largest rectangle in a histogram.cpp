#include <bits/stdc++.h> 
using namespace std;

// Approach-1

 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n=heights.size();
   stack<int> st;
   int leftSmall[n];
   int rightSmall[n];
   int maxA=0;
   for(int i=0;i<n;i++){
     while(!st.empty() && heights[st.top()]>=heights[i]){
       st.pop();
     }
     if(st.empty()) leftSmall[i]=0;
     else leftSmall[i]=st.top()+1;
     st.push(i);
   }
  //  clear stack to be reused
   while(!st.empty()) st.pop();
   for(int i=n-1;i>=0;i--){
     while(!st.empty() && heights[st.top()]>=heights[i]){
       st.pop();
     }
     if(st.empty()) rightSmall[i]=n-1;
     else rightSmall[i]=st.top()-1;
     st.push(i);
   }
   for(int i=0;i<n;i++){
     maxA=max(maxA,(rightSmall[i]-leftSmall[i]+1)*heights[i]);
   }
   return maxA;
 }

//  Appraoch-2

 int largestRectangle(vector < int > & histo) {
   // Write your code here.
   stack<int> st;
   int maxA=0;
   int n=histo.size();
   for(int i=0;i<=n;i++){
     while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
       int height=histo[st.top()];
       st.pop();
       int width;
       if(st.empty()) width=i;
       else width=i-st.top()-1;
       maxA=max(maxA,width*height);
     }
     st.push(i);
   }
   return maxA;
   
 }