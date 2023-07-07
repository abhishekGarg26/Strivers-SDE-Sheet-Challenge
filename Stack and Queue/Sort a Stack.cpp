#include <bits/stdc++.h> 
using namespace std;

void sortedInsert(stack<int> &stack,int num){
	if(stack.empty() || stack.top()<num) {
		stack.push(num);
		return;
	}
	int n=stack.top();
	stack.pop();
	sortedInsert(stack,num);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack,num);

	
}