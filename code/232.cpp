#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        pushStk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int item;
        if(popStk.empty()){
            while(!pushStk.empty()){
                popStk.push(pushStk.top());
                pushStk.pop();
            }
        }
        item = popStk.top();
        popStk.pop();
        return item;
    }

    /** Get the front element. */
    int peek() {
        int item;
        if(popStk.empty()){
            while(!pushStk.empty()){
                popStk.push(pushStk.top());
                pushStk.pop();
            }
        }
        item = popStk.top();
        return item;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStk.empty() && popStk.empty();
    }

private:
    stack<int> pushStk, popStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */