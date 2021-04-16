/*
leet218


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>> buildings) {
        // O(N^2), WrongAnswer
        using Pair = pair<int, int>;
        set<Pair> tree; 
        vector<vector<int>> ans;
        for (const auto& v: buildings) {
            auto x1 = v[0], x2 = v[1], y = v[2];
            if (tree.empty()) {
                ans.push_back({x1, y});
                tree.insert({x2, y}); continue;
            }

            auto& [_x2, _y] = *tree.rbegin();
            if (x1 > _x2) {
                ans.push_back({_x2, 0});
                ans.push_back({x1, y});
                tree.insert({x2, y}); continue;
            }


            auto parallel = false, additional = false, covered = false; auto x = x1, ay = 0;
            for (auto p=tree.rbegin(); p != tree.rend(); ++p) {
                auto& [_x2, _y] = *p;
                if (x1 > _x2) break;
                if (x2 <= _x2) {
                    if (y <= _y) covered = true;
                    else if (x2 < _x2) additional = true, ay = max(ay, _y) ;
                }
                if (y == _y) { parallel = true; break; }
                if (y < _y) x = max(x, _x2);
            }
            if (not parallel and not covered) {
                auto overlap = false;
                for (auto& v: ans) {
                    if (x == v[0]) v[1] = max(v[1], y), overlap = true;
                }
                if (not overlap) 
                    ans.push_back({x, y});
            }
            if (not covered and additional) {
                ans.push_back({x2, ay});
            }
            
            tree.insert({x2, y});
        }

        const auto& v = buildings.back();
        auto  x2 = v[1];
        ans.push_back({x2, 0});
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.getSkyline({{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}}) << endl;
    cout << sol.getSkyline({{0,2,3},{2,5,3}}) << endl;
    cout << sol.getSkyline({{1,2,1},{1,2,2},{1,2,3}}) << endl;
    cout << sol.getSkyline({{2,14,4},{4,8,8},{6,16,4}}) << endl;
    cout << sol.getSkyline({{4,9,10},{4,9,15},{4,9,12},{10,12,10},{10,12,8}}) << endl;
    return 0;
}
