/*
leet1631


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int minimumEffortPath(const vector<vector<int>>& heights) {
        // O(N M log NM), Dijkstra
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e6));

        using Tuple3 = tuple<int, int, int>;
        auto cmp = [&](const Tuple3& t1, const Tuple3& t2) {
            auto& [d1, x1, y1] = t1;
            auto& [d2, x2, y2] = t2;
            return d1 > d2;
        };
        priority_queue<Tuple3, vector<Tuple3>, decltype(cmp)> Q(cmp);
        Q.push({0, 0, 0}); dist[0][0] = 0;

        const int Neighbors[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!Q.empty()) {
            auto [d, x, y] = Q.top(); Q.pop(); // 注意此处要使用 auto, 不可以使用 ref
            if (x == n-1 and y == m-1) 
                return d;

            for (const auto& [dx, dy]: Neighbors) {
                auto nx = x + dx, ny = y + dy;
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

                auto newd = max(d, abs(heights[x][y] - heights[nx][ny]));
                if (dist[nx][ny] > newd) {
                    dist[nx][ny] = newd;
                    Q.push({newd, nx, ny});
                }
            }
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.minimumEffortPath({{3}}) << endl;
    cout << sol.minimumEffortPath({{1,2,2},{3,8,2},{5,3,5}}) << endl;
    cout << sol.minimumEffortPath({{1,2,3},{3,8,4},{5,3,5}}) << endl;
    cout << sol.minimumEffortPath({{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}}) << endl;
    return 0;
}
