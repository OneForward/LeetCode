/*
leet232


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class MyQueue {
public:
    stack<int> S;
    stack<int> Stmp;
    int top;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) { 
        if (S.empty()) top = x;
        S.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  
        int ret = top;
        while (S.size()) Stmp.push(S.top()), S.pop();
        Stmp.pop(); if (Stmp.size()) top = Stmp.top();
        while (Stmp.size()) S.push(Stmp.top()), Stmp.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S.empty();
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


int main(int argc, char const *argv[])
{

    return 0;
}
