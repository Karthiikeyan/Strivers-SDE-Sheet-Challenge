#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	// Write your code here
	priority_queue<int, vector<int>, greater<int>> st;
	while(!stack.empty()){
		st.push(stack.top());
		stack.pop();
	}
	while(!st.empty()){
		stack.push(st.top());
		st.pop();
	}
	
}