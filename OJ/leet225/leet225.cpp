/*
leet225


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

class MyStack {
public:
    queue<int> Q;
    queue<int> Qtmp;
    int front;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x); front = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (Q.size() > 2) Qtmp.push(Q.front()), Q.pop();
        front = Q.front(); Qtmp.push(Q.front()), Q.pop();
        while (!Qtmp.empty()) Q.push(Qtmp.front()), Qtmp.pop();
        int ans = Q.front(); Q.pop(); 
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return front;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
