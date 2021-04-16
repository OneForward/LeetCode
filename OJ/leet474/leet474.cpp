/*
leet474


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int findMaxForm(const vector<string>& strs, int m, int n) {
        // 300ms, 动态规划, 二维DP, O(MNL)
        vector<vector<int>> f(m+1, vector<int>(n+1));

        for (const auto& s: strs) {
            int x = count(s.begin(), s.end(), '0'), y = s.size() - x;
            for (auto u = m; u >= x; --u) {
                for (auto v = n; v >= y; --v) {
                    f[u][v] = max(f[u][v], f[u-x][v-y] + 1 );
                }
            }
        }
        return f[m][n];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaxForm({"10", "0001", "111001", "1", "0"}, 5, 3) << endl;
    cout << sol.findMaxForm({"10", "0", "1"}, 1, 1) << endl;

    return 0;
}
