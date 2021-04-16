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
        // O(N log N)
        multiset<pair<int, int>> tree; 
        for (const auto& v: buildings) {
            auto x1 = v[0], x2 = v[1], y = v[2];
            tree.insert({x1, -y});
            tree.insert({x2, y});
        }

        int lasty = 0;
        multiset<int> Y({0});
        vector<vector<int>> ans;
        for (const auto& [x, y]: tree) {
            if (y < 0) Y.insert(-y);
            else Y.erase(Y.find(y));

            auto maxY = *Y.rbegin();
            if (lasty != maxY) {
                lasty = maxY;
                ans.push_back({x, maxY});
            }
        }
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
