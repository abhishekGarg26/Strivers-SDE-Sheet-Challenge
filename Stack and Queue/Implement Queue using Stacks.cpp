#include <bits/stdc++.h> 
using namespace std;

// Approach -1 O(n)

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s2.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    
    int pop() {
        if(s1.size()==0) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        if(s1.size()==0) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Approach - 2 O(1) -> amortized  

class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int> input;
    stack<int> output;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int x) {
        // Implement the enqueue() function.
        input.push(x);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if((input.size()+output.size())==0) return -1;
        int x;
        if(!output.empty()){
            x=output.top();
            output.pop();
        }else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            x=output.top();
            output.pop();
        }
        return x;
    }

    int peek() {
        // Implement the peek() function here.
        if((input.size()+output.size())==0) return -1;
        int x;
        if(!output.empty()){
            x=output.top();
        }else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            x=output.top();
        }
        return x;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (input.size()+output.size())==0;

    }
};