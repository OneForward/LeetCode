/*
leet576


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> f(m+2, vector<int>(n+2)), g;
        for (int i = 0; i < m+2; ++i) {
            f[i][0] = f[i][n+1] = 1;
        }
        for (int j = 0; j < n+2; ++j) {
            f[0][j] = f[m+1][j] = 1;
        }

        const int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        const int MOD = 1e9 + 7;
        while (N--) {
            g = f;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    f[i][j] = 0;
                    for (const auto& [dx, dy]: D) {
                        auto x = i + dx, y = j + dy;
                        f[i][j] += g[x][y]; f[i][j] %= MOD;
                    }
                }
            }
        }
        return f[i+1][j+1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findPaths(2,2,2,0,0) << endl;
    cout << sol.findPaths(1,3,3,0,1) << endl;
    return 0;
}
