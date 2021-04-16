/*
leet706


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <list>
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

struct Node
{
    int key, value;
};

int h(int x) { return x % 10009; }
class MyHashMap {
public:
    vector<list<Node>> v;

    /** Initialize your data structure here. */
    MyHashMap(): v(10009) {  }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto&& L = v[h(key)];
        auto pos = find_if(L.begin(), L.end(), [&](const Node& node) { return node.key == key; });
        if (pos == L.end()) L.push_back({key, value});
        else pos->value = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto&& L = v[h(key)];
        auto pos = find_if(L.begin(), L.end(), [&](const Node& node) { return node.key == key; });
        return pos == L.end() ? -1 : pos->value;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto&& L = v[h(key)];
        L.remove_if([&](const Node& node) { return node.key == key; });
    }
};


int main(int argc, char const *argv[])
{
    MyHashMap myHashMap;
    myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
    myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
    cout << endl << myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
    cout << endl << myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
    myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
    cout << endl << myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
    myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
    cout << endl << myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
 
    return 0;
}
