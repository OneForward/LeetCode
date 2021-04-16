/*
leet391


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

class Solution {
public:
    bool isRectangleCover(vector<vector<int>> rectangles) {
        // O(N^2), 扫描线法 
        const int IN = 1, OUT = -1;
        using Tuple = tuple<int, int, int, int>;
        multiset<Tuple> tree;
        for (const auto& v: rectangles) { // O(N log N)
            auto x1 = v[0], y1= v[1], x2 = v[2], y2 = v[3];
            tree.insert({y1, IN, x1, x2});
            tree.insert({y2, OUT, x1, x2});
        }

        using Pair = pair<int, int>;
        vector<Pair> active;
        bool isok = true;
        auto query = [&]() -> pair<int, int>  { // O(N)
            auto [lastx1, lastx2] = active[0]; lastx2 = lastx1;
            for (const auto& [x1, x2]: active) {
                if (lastx2 != x1) { isok = false; return {0, 0}; }
                lastx2 = x2;
            }
            return {lastx1, lastx2};
        };

        auto y1 = get<0>(*tree.begin());
        auto prevx1 = 0, prevx2 = 0;
        for (const auto& [y2, type, x1, x2]: tree) { // N loops
            if (y2 != y1) {
                auto [lastx1, lastx2] = query(); // O(N)
                if (not isok) 
                    return false;
                if (prevx1 == prevx2) prevx1 = lastx1, prevx2 = lastx2;
                else if (prevx1 != lastx1 or prevx2 != lastx2) 
                    return false;
            }
            auto pos = lower_bound(active.begin(), active.end(), Pair{x1, x2});
            if (type == IN) active.insert(pos, Pair{x1, x2}); // O(N)
            else active.erase(pos); // O(N)
            y1 = y2;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {1,1,3,3},
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {3,2,4,4},
            {1,3,2,4},
            {2,3,3,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,2,3},
            {1,3,2,4},
            {3,1,4,2},
            {3,2,4,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {1,3,2,4},
            {3,2,4,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {1,3,2,4},
            {3,2,4,4}
            }) << endl;
    return 0;
}
