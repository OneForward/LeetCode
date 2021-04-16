/*
leet650


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
    int minSteps(int N) {
        if (N == 1) return 0;
        auto M = N / 2;
        vector<vector<int>> f(N+1, vector<int>(M+1, INT_MAX)); 
        for (int m = 0; m <= M; ++m) f[0][m] = 0;
        f[1][1] = 0;
        for (int m = 1; m <= M; ++m) {
            int n = 2 * m; f[n][m] = INT_MAX;
            for (int i = 1; i <= max(m/2, 1); ++i) if (f[m][i] != INT_MAX) f[n][m] = min(f[n][m], f[m][i] + 2 );
            for (n = 2*m+1; n <= N; ++n) {
                if (f[n-m][m] != INT_MAX) f[n][m] = f[n-m][m] + 1;
            }
        }
        cout << f << endl;
        int minVal = INT_MAX; 
        for (auto&& x: f[N]) minVal = min(minVal, x);
        return minVal;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minSteps(10) << endl;
    cout << sol.minSteps(5) << endl;
    cout << sol.minSteps(3) << endl;
    cout << sol.minSteps(2) << endl;
    cout << sol.minSteps(1) << endl;
    return 0;
}
