/*
leet341


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
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
  public:
    vector<NestedInteger> v;
    int x{};

    NestedInteger(int x): x{x} {}
    NestedInteger(vector<int> vi) {
        for (auto &&x : vi) v.emplace_back(x);
    }
    NestedInteger(vector<NestedInteger> v): v{v} {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return v.empty(); } 
 
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return x; } 
 
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const { return v; } ;
};

class NestedIterator {
public:
    using Iter = vector<NestedInteger>::const_iterator;
    stack<Iter> Sbegin, Send;
    Iter p;

    NestedIterator(const vector<NestedInteger> &nestedList): p{nestedList.begin()} {
        Send.push(nestedList.end());
        move_to_leaf(p);
    }

    void move_to_leaf(Iter p) {
        while (true) {
            while (p == Send.top()){
                if (Sbegin.empty()) return ;
                p = Sbegin.top(), Sbegin.pop(), Send.pop();
                if (p != Send.top()) ++p;
            }
            while (p != Send.top() and not p->isInteger()) {
                auto&& L = p->getList();
                Sbegin.push(p); Send.push(L.end()); p = L.begin(); 
            }
            if (p != Send.top() and p->isInteger()) break;
        }
    }
    
    int next() {
        auto x = p->getInteger(); p++;
        move_to_leaf(p);
        return x;
    }
    
    bool hasNext() {
        return not (Sbegin.empty() and p == Send.top());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


int main(int argc, char const *argv[])
{
    NestedInteger v1(vector<int>{1,1}), v2{2}, v3(vector<int>{1,1});
    auto v = vector({v1, v2, v3});
    NestedIterator iter(v);
    while (iter.hasNext()) 
    cout << iter.next() << ", ";
    return 0;
}
