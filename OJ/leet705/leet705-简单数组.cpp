/*
leet705


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

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> L;
    MyHashSet() : L(100005) {

    }
    
    void add(int key) {
        L[key] = true;
    }
    
    void remove(int key) {
        L[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return L[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
