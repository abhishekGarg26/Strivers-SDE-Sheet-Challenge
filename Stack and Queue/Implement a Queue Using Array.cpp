#include <bits/stdc++.h> 

class Queue {
public:
    int frontind;
    int rear;
    int n=5000;
    int arr[5000];
    int size;
    Queue() {
        // Implement the Constructor
        frontind=0;
        rear=0;
        size=0;
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==n) return;
        arr[rear%n]=data;
        rear++;
        size++;
        return;

    }

    int dequeue() {
        // Implement the dequeue() function
        if(size==0) return -1;
        int x=arr[frontind%n];
        frontind++;
        size--;
        return x;
    }

    int front() {
        // Implement the front() function
        if(size==0) return -1;
        return arr[frontind%n];
    }
};