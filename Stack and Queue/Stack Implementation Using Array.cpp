#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int topidx;
    int size;
    int arr[1000];
    Stack(int capacity) {
        // Write your code here.
        topidx=-1;
        size=capacity;
    }
    void push(int num) {
        // Write your code here.
        if(topidx<size-1) arr[++topidx]=num;
        return;
    }

    int pop() {
        // Write your code here.
        if(topidx==-1) return -1;
        int x=arr[topidx];
        topidx--;
        return x;
    }
    
    int top() {
        // Write your code here.
        if(topidx==-1) return -1;
        return arr[topidx];
    }
    
    int isEmpty() {
        // Write your code here.
        return topidx==-1;
    }
    
    int isFull() {
        // Write your code here.
        return topidx==size-1;
    }
    
};