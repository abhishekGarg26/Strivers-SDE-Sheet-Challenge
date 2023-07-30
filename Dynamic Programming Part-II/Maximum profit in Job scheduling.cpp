#include <bits/stdc++.h> 
using namespace std;

static bool comparator(vector<int> a1,vector<int> a2){
        return (a1[1]>a2[1]);
    }
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
        int n=jobs.size();
     sort(jobs.begin(),jobs.end(),comparator);
        int maxi=jobs[0][0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,jobs[i][0]);
        }
        int slot[maxi+1];
        for(int i=0;i<=(maxi+1);i++){
            slot[i]=-1;
        }
        int jobProfit=0,countJobs=0;
        for(int i=0;i<n;i++){
            for(int j=jobs[i][0];j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    jobProfit+=jobs[i][1];
                    countJobs++;
                    break;
                }
            }
        }
        
        return jobProfit;
}
