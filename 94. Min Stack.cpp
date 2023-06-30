#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> st;
	int mini;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				mini = num;
				st.push(num);
			}
			else{
				if(mini<=num){
					st.push(num);
				}else{
					int prev = num;
					num = 2*num-mini;
					mini = prev;
					st.push(num);
				}
			}

		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(!st.empty()){
				int ans = st.top();
				if(ans>=mini){
					st.pop();
					return ans;
				}else{
					int prev = mini;
					mini = 2*mini - ans;
					st.pop();
					return prev;
				}
			}
			return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(!st.empty()){
				int ans = st.top();
				if(ans >= mini) return ans;
				else return mini;
			}
			return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(!st.empty()){
				return mini;
			}
			return -1;
		}
};