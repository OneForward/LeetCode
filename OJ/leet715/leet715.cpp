/*
leet715


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





// 维护一个  包含  不相交区间 的数据结构
// add, remove: O(N)
// query: O(log N)
// 代码的妙处在于提示了 set, map 等平衡二叉树内部的遍历同时修改的可行性
class RangeModule {
public:
    
    map<int, int> M;
    RangeModule() {}
    
    void addRange(int lft, int rht) {
        auto a = M.lower_bound(lft);
        auto b = M.lower_bound(rht);
        if (a == M.end()) M[rht] = lft;
        else {
            auto start = min(lft, a->second);
            while (a != b) {
                auto p = a; a++;
                M.erase(p);
            }
            if (b != M.end() and b->second <= rht) b->second = start;
            else M[rht] = start;
        }
    }
    
    bool queryRange(int lft, int rht) {
        auto b = M.lower_bound(rht);
        return b != M.end() and b->second <= lft;
    }
    
    void removeRange(int lft, int rht) {
        auto a = M.lower_bound(lft);
        auto b = M.lower_bound(rht);
        if (a == M.end()) return;
        else {
            auto start = a->second;
            while (a != b) {
                auto p = a; a++;
                M.erase(p);
            }
            if (b != M.end()) b->second = max(rht, b->second);
            if (start < lft) M[lft] = start;
        }
    }
};




int main(int argc, char const *argv[])
{
    cout << boolalpha;

    RangeModule rangeModule;
    // rangeModule.addRange(10, 20);
    // rangeModule.removeRange(14, 16);
    // cout << rangeModule.queryRange(10, 14) << endl;
    // cout << rangeModule.queryRange(13, 15) << endl;
    // cout << rangeModule.queryRange(16, 17) << endl;

    // rangeModule.addRange(10, 180);
    // rangeModule.addRange(150, 200);
    // rangeModule.addRange(250, 500);
    // cout << rangeModule.queryRange(50, 100) << endl;
    // cout << rangeModule.queryRange(180, 300) << endl;
    // cout << rangeModule.queryRange(600, 1000) << endl;
    // rangeModule.removeRange(50, 150);
    // cout << rangeModule.queryRange(50, 100) << endl;


    rangeModule.addRange(6, 8);
    rangeModule.removeRange(7, 8);
    rangeModule.removeRange(8, 9);
    rangeModule.addRange(8,9);
    rangeModule.removeRange(1,3);
    rangeModule.addRange(1,8);
    cout << rangeModule.queryRange(2,4) << endl;
    cout << rangeModule.queryRange(2,9) << endl;
    cout << rangeModule.queryRange(4,6) << endl;
    return 0;
}
