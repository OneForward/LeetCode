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
    /** initialize your data structure here. */
    multiset<int> S;
    multiset<int>::iterator mid;

    MedianFinder(): mid{S.begin()} {
    }
    
    void addNum(int num) {
        // printf("inserting %d...", num); print();
        S.insert(num);
        if (S.size() == 1) { mid = S.begin(); return; }
        if (S.size() % 2 == 0 and num >= *mid) mid++;
        if (S.size() % 2 == 1 and num < *mid) mid--;
    }
    
    double findMedian() {
        int n = S.size();
        return (*mid + (double)*next(mid, n%2-1)) / 2.;
    }

    void print() {
        for (const auto it: S) {
            cout << it << ", ";
        }
        if (mid != S.end())
        cout << ": mid = " << *mid; 
        cout << endl;
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
    // sol.addNum(1) ;  sol.print();
    sol.addNum(2) ;  sol.print();
    cout << sol.findMedian() << endl;
    sol.addNum(3);   sol.print();
    cout << sol.findMedian() << endl;

    return 0;
}
