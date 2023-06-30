#include <bits/stdc++.h> 
class Queue {
    vector<int> ans;
    int i = 0;
public:
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return i>=ans.size();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        ans.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        return i>=ans.size() ? -1 : ans[i++];
    }

    int front() {
        // Implement the front() function
        return i>=ans.size() ? -1 : ans[i];
    }
};