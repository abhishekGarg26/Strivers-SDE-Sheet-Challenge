#include <bits/stdc++.h>
using namespace std;

int countStudents(int *A,int len,int pages){
    int students=1,pagesStudent=0,i=0;
    for(i=0;i<len;i++){
        if(pagesStudent+A[i]<=pages){
            pagesStudent+=A[i];
        }else{
            students++;
            pagesStudent=A[i];
        }
    }
    return students;
}
int books(int* A, int n1, int B) {
    if(n1<B) return -1;
    // int low=INT_MIN,i=0,high=0;
    // for(i=0;i<n1;i++){
    //     if(A[i]>low)
    //     low=A[i];
    //     high+=A[i];
    // }
    int low=*max_element(A,A+n1);
	int high=accumulate(A,A+n1,0);
    while(low<=high){
        int mid=(low+high)>>1;
        int students=countStudents(A,n1,mid);
        if(students>B) low=mid+1;
        else high=mid-1;
    }
    return low;
}