/*
leet155


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> S, Smin;
    
    MinStack() {}
    
    void push(int x) {
        S.push(x); 
        if (!Smin.empty()) Smin.push(min(Smin.top(), x));
        else Smin.push(x);
    }
    
    void pop() {
        S.pop(); Smin.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return Smin.top();
    }
};



int main(int argc, char const *argv[])
{
    // Solution sol;   

    return 0;
}
