#include <bits/stdc++.h> 
using namespace std;

// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
	stack<long long> st;
    long long mini;
    	
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			while(!st.empty()) st.pop();
        	mini=INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			// Write your code here.
		long long value=val;
        if(st.empty()){
            mini=value;
            st.push(value);
        }else{
            if(value<mini){
                st.push(2*value*1LL-mini);
                mini=value;
            }else{
                st.push(value);
            }
        }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
		if(st.empty()) return -1;
        long long el=st.top();
        st.pop();
        if(el<mini){
			int val=mini;
            mini=2*mini-el;
			return (int)val;
        }
		return (int)el;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
		if(st.empty()) return -1;
        long long el=st.top();
        if(el<mini) return (int)mini;
        return (int)el;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty()) return -1;
			return (int)mini;
		}
};