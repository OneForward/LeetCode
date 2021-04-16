/*
leet062


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
    int uniquePaths(int m, int n) {
        // 0ms
        if (m < n) return uniquePaths(n, m);

        vector<int> f(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j-1];
            }
        }
        return f[n-1];
    }
    int uniquePaths2(int m, int n) {
        // 4ms
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) f[i][0] = 1;
        for (int j = 1; j < n; ++j) f[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    for (auto m: {1, 2, 3, 4, 5, 6, 7}) {
        for (auto n: {1, 2, 3, 4, 5}) {
            cout << "m = " << m << ", n = " << n << ": ";
            cout << sol.uniquePaths(m, n) << endl;
        }
    }
    return 0;
}
