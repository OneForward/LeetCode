/*
leet064


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {        
        // 12ms, Space O(N) Time O(MN)
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n+1, INT_MAX);
        f[1] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[j] = min(f[j] , f[j-1]) + grid[i-1][j-1];
            }
        }
        return f[n];
    }
    int minPathSum2(vector<vector<int>>& grid) {
        // 12ms Space O(MN) Time O(MN)
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m+1, vector<int>(n+1, INT_MAX));
        f[1][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i-1][j] , f[i][j-1]) + grid[i-1][j-1];
            }
        }
        return f[m][n];
    }
};

int main(int argc, char const *argv[])
{

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution sol;   
    cout << sol.minPathSum(grid) << endl;
    return 0;
}
