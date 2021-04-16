/*
leet380


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
#include <functional>
#include <utility>
#include <random>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class RandomizedSet {
public:
    // 哈希表 + 线性表
    vector<int> List;
    unordered_map<int, int> M;
    std::mt19937 gen{}; //Standard mersenne_twister_engine seeded with rd()
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (M.count(val)) return false;
        M[val] = List.size();
        List.push_back(val);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (M.count(val) == 0) return false;
        M[List.back()] = M[val]; List[M[val]] = List.back();
        List.pop_back(); M.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        uniform_int_distribution<> dist(0, List.size()-1);
        return List[dist(gen)];
    }
};




int main(int argc, char const *argv[])
{
    // Solution sol;   

    return 0;
}
