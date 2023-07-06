#include <bits/stdc++.h> 
using namespace std;

class data{
    public:
    int value,apos,vpos;
    data(int val,int ap,int vp){
        value=val;
        apos=ap;
        vpos=vp;
    }
};
class Ans : public data{
struct mycomp{
    bool operator()(data &d1,data &d2){
        return d1.value>d2.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<data, vector<data>, mycomp> pq;
    for(int i=0;i<k;i++){
        data d(arr[i][0],i,0);
        pq.push(d);
    }
    while(!pq.empty()){
        data curr=pq.top(); pq.pop();
        ans.push_back(curr.value);
        int ap=curr.apos;
        int vp=curr.vpos;
        if(vp+1 < arr[ap].size()){
            data d(arr[ap][vp+1],ap,vp+1);
            pq.push(d);
        }
    }
    return ans;
}
};