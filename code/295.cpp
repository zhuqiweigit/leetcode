#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    int cnt;
    /** initialize your data structure here. */
    MedianFinder() {
        cnt = 0;
    }

    void addNum(int num) {
        cnt++;
        left_heap.push(num);
        num = left_heap.top();
        left_heap.pop();
        right_heap.push(num);
        if(right_heap.size() > left_heap.size()){
            num = right_heap.top();
            right_heap.pop();
            left_heap.push(num);
        }
    }

    double findMedian() {
        if(cnt % 2 == 0){
            double a = left_heap.top();
            double b = right_heap.top();
            return (a + b) / 2;
        }else{
            return left_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */