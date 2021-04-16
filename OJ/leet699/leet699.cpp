/*
leet699


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
    vector<int> fallingSquares(const vector<vector<int>>& positions) {
        // O(N^2) 朴实无华
        using Tuple = tuple<int, int, int>;
        vector<Tuple> active;
        vector<int> ans; int last = 0;
        for (const auto& pos: positions) {
            auto x = pos[0], h = pos[1], y = h;
            for (const auto& [x1, x2, y0]: active ) {
                if (x + h <= x1 or x >= x2) continue;
                else y = max(y, h + y0);
            }
            active.push_back({x, x+h, y});
            
            last = max(last, y);
            ans.push_back(last);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.fallingSquares({{1,2},{2,3},{6,1}}) << endl;
    cout << sol.fallingSquares({{100,100},{200,100}}) << endl;
    return 0;
}
