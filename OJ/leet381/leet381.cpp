/*
leet381


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class RandomizedCollection {
public:
    // 哈希表 套 哈希表 套 线性表
    // 全部 O(1) 的 插入，删除，随机索引，72ms, 77%
    vector<int> List;
    unordered_map<int, unordered_set<int>> M;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int x) {
        auto not_already_existed = false;
        if (M.count(x) == 0)  not_already_existed = true;
        M[x].insert(List.size()); 
        List.push_back(x);
        return not_already_existed;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int x) {
        if (M.count(x) == 0) return false;
        
        auto xback = List.back();
        if (x == xback) {
            M[x].erase(List.size()-1);
            List.pop_back();
            if (M[x].empty()) M.erase(x);
            return true;
        }

        auto i = *M[x].begin();
        List[i] = xback;
        M[xback].erase(List.size()-1);
        M[xback].insert(i);
        M[x].erase(i); if (M[x].empty()) M.erase(x);
        List.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return List[rand() % List.size()];
    }
};




int main(int argc, char const *argv[])
{
    RandomizedCollection randCollection;
    cout << boolalpha;
    cout << randCollection.insert(0) << endl;
    cout << randCollection.remove(0) << endl;
    cout << randCollection.insert(-1) << endl;
    cout << randCollection.remove(0) << endl;
    cout << randCollection.getRandom() << endl;
    return 0;
}
