#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    private:
    stack<int> input;
    stack<int> output;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!output.empty()){
            int ans = output.top();
            output.pop();
            return ans;
        }else{
            if(input.empty()) return -1;
            else{
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
                int ans = output.top();
                output.pop();
                return ans;
            }
            
        }
    }

    int peek() {
        // Implement the peek() function here.
        if(!output.empty()){
            return output.top();
        }else{
            if(input.empty()) return -1;
            else{
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
                return output.top();
            }
            
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (output.empty() && input.empty());
    }
};