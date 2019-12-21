#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        myQueue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = myQueue.size();
       for(int i = 0; i < size - 1; i++){
           myQueue.push(myQueue.front());
           myQueue.pop();
       }
       int x = myQueue.front();
       myQueue.pop();
       return x;
    }

    /** Get the top element. */
    int top() {
        int size = myQueue.size(), x;
        for(int i = 0; i < size; i++){
            myQueue.push(myQueue.front());
            x = myQueue.front();
            myQueue.pop();
        }
        return x;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
    }
private:
    queue<int> myQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */