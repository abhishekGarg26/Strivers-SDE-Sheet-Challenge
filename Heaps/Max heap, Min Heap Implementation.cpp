#include<bits/stdc++.h>

using namespace std;

// Max Heap

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int value){
        size=size+1;
        int index=size;
        arr[index]=value;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
        return;
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"No Element To Delete";
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<=size && arr[leftIndex]>arr[i] && arr[leftIndex]>arr[rightIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }else if(rightIndex<=size && arr[rightIndex]>arr[i] && arr[rightIndex]>arr[leftIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }else{
                return;
            }
        }
        return;
    }

    void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
     
    void heapSort(int arr[],int n){
        int size=n;
        while(size>1){
            swap(arr[1],arr[size]);
            size--;
            heapify(arr,size,1);

        }
    }
};

int main(){
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(49);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[]={-1,49,54,53,50,52};
    int n=5;
    cout<<endl;
    for(int i=n/2;i>0;i--)
        h.heapify(arr,n,1);
    h.heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    

}


// Min Heap 

void insert(vector<int> &arr,int value){
    int index=arr.size();
    arr.push_back(value);
    while(index>0){
        int parent=(index-1)/2;
        if(arr[parent]>arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            return;
        }
    }
    return;

}
void heapify(vector<int> &arr,int n,int i){
    int leftIndex=2*i+1;
    int rightIndex=2*i+2;
    int minimum=i;
    if(leftIndex<n && arr[leftIndex]<arr[minimum]){
        minimum=leftIndex;
    }
    if(rightIndex<n && arr[rightIndex]<arr[minimum]){
        minimum=rightIndex;
    }
    if(minimum!=i){
        swap(arr[minimum],arr[i]);
        heapify(arr,n,minimum);
    }
}
void deleteFromHeap(vector<int> &arr,vector<int> &ans){
    int size=arr.size();
    ans.push_back(arr[0]);
    arr[0]=arr[size-1];
    size--;
    heapify(arr,size,0);
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> arr;
    vector<int> ans;
    for(auto it:q){
        if(it[0]==0){
            insert(arr,it[1]);
        }
        else{
            deleteFromHeap(arr,ans);
        }
    }
    return ans;
}
