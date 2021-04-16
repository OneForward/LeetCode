/*
leet295


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class MedianFinder {
public:
    
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    MedianFinder() { }
    
    void addNum(int num) {
        int n = maxQ.size(), m = minQ.size();
        if (n == m) {
            if (m and num >= minQ.top()) minQ.push(num);
            else maxQ.push(num);
        }
        else if (n > m) {   
            if (num >= maxQ.top()) minQ.push(num);
            else maxQ.push(num), minQ.push(maxQ.top()), maxQ.pop();
        }
        else {
            if (num <= minQ.top()) maxQ.push(num);
            else minQ.push(num), maxQ.push(minQ.top()), minQ.pop();
        }
    }
    
    double findMedian() {
        int n = maxQ.size(), m = minQ.size();
        if (n > m) return maxQ.top();
        if (n < m) return minQ.top();
        return (maxQ.top() + (double)minQ.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main(int argc, char const *argv[])
{
    MedianFinder sol;
    sol.addNum(1) ;  
    sol.addNum(2) ;  
    cout << sol.findMedian() << endl;
    sol.addNum(3);   
    cout << sol.findMedian() << endl;

    return 0;
}
