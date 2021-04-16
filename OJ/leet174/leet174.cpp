/*
leet174


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // 16ms, O(MN)
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])  - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> M = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    Solution sol;   
    cout << sol.calculateMinimumHP(M) << endl;
    return 0;
}
